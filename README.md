# RealSense Camera Test

[![Codacy Badge](https://app.codacy.com/project/badge/Grade/4884f3b19f68456ebb3c6ce409759686)](https://app.codacy.com?utm_source=gh&utm_medium=referral&utm_content=&utm_campaign=Badge_grade)

This C++ application is a basic RealSense camera streamer. It uses the librealsense library to communicate with a RealSense camera, and streams the color and depth data from the camera.

## Features

- Displays device information like serial number, firmware version, USB connection type, and physical port.
- Streams color and depth data from the camera.
- Handles errors when the camera isn't correctly connected or data isn't received.
- Calculates and displays the received frames per second.

## Dependencies

- [librealsense2](https://github.com/IntelRealSense/librealsense)

## Building and Running

To build and run the application, follow these steps:

1. Clone the repository and navigate to the source code's directory.
2. Compile the code using your preferred C++ compiler.
3. Run the resulting executable. If the RealSense camera is connected correctly and detected, you will start seeing the color and depth data stream and the frames per second.

## Interrupting the Stream

Pressing CTRL+C during runtime will trigger an interrupt signal. This causes the application to display a message, clean up, and terminate.

## Note

This application is a basic example of using the librealsense library to stream data from a RealSense camera. It is not intended for production use, and doesn't handle all possible error cases or camera configurations.
