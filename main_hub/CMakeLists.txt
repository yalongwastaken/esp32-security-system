# minimum CMake version
cmake_minimum_required(VERSION 3.16)

# set component directories
# components/       - hub-only drivers
# ../components/    - drivers shared with remote_node
set(EXTRA_COMPONENT_DIRS components ../components)

# include ESP-IDF build system
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# project name
project(sentinel_main_hub)