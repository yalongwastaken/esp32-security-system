# minimum CMake version
cmake_minimum_required(VERSION 3.16)

# set component directories
set(EXTRA_COMPONENT_DIRS components)

# include ESP-IDF build system
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# project name
project(esp32-remote-node)