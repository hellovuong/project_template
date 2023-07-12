cmake_minimum_required(VERSION 3.16..3.23)
project(damn_you_realsense)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

find_package(realsense2)

add_executable(damn_you_realsense main.cpp)

target_include_directories(damn_you_realsense PUBLIC
        ${realsense_INCLUDE_DIR}
        )

target_link_libraries(damn_you_realsense
        ${realsense2_LIBRARY}
        )
