#include <iostream>
#include <librealsense2/h/rs_sensor.h>
#include <librealsense2/hpp/rs_frame.hpp>
#include <librealsense2/hpp/rs_types.hpp>
#include <librealsense2/rs.hpp>

int main() {
    rs2::context ctx;
    rs2::pipeline pipe;
    rs2::config cfg;

    cfg.enable_stream(RS2_STREAM_COLOR, 848, 480, RS2_FORMAT_BGR8, 30);
    cfg.enable_stream(RS2_STREAM_DEPTH, 848, 480, RS2_FORMAT_Z16, 30);
    auto list =
            ctx.query_devices();// Get a snapshot of currently connected devices

    if (list.size() == 0) {
        throw std::runtime_error("No device detected. Is it plugged in?");
    }

    rs2::device dev = list.front();

    std::string serial_number = dev.get_info(RS2_CAMERA_INFO_SERIAL_NUMBER);
    std::string firmware_version = dev.get_info(RS2_CAMERA_INFO_FIRMWARE_VERSION);
    std::string usb_type = dev.get_info(RS2_CAMERA_INFO_USB_TYPE_DESCRIPTOR);
    std::string physical_port = dev.get_info(RS2_CAMERA_INFO_PHYSICAL_PORT);
    std::string designed_usb = dev.get_info(RS2_CAMERA_INFO_USB_TYPE_DESCRIPTOR);

    std::cout << "Device Serial Number: " << serial_number << std::endl;
    std::cout << "Device Firmware Version: " << firmware_version << std::endl;
    std::cout << "USB Connection Type: " << usb_type << std::endl;
    std::cout << "Physical port: " << physical_port << std::endl;
    std::cout << "Designated USB: " << designed_usb << std::endl;

    try {
        pipe.start(cfg);
    } catch (const rs2::error &e) {
        std::cerr << "Can not start pipeline " << e.what() << std::endl;
    }

    int frame_counter = 0;
    auto start_time = std::chrono::high_resolution_clock::now();

    while (true) {
        rs2::frameset data;
        try {
            data = pipe.wait_for_frames();
        } catch (const rs2::error &e) {
            std::cerr << "Failed to wait: " << e.what() << std::endl;
        }

        rs2::frame color_frame = data.get_color_frame();
        rs2::frame depth_frame = data.get_depth_frame();

        if (!color_frame) {
            std::cout
                    << "No color data received. Check if camera is connected properly."
                    << std::endl;
            continue;
        } else if (!depth_frame) {
            std::cout
                    << "No depth data received. Check if camera is connected properly."
                    << std::endl;
            continue;
        }

        frame_counter++;
        auto current_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::seconds>(
                                current_time - start_time)
                                .count();

        if (duration >= 1) {
            std::cout << "Received FPS: " << frame_counter / duration << std::endl;
            frame_counter = 0;
            start_time = current_time;
        }
    }

    return 0;
}
