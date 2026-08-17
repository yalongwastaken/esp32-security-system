# minimum CMake version
cmake_minimum_required(VERSION 3.16)

# set component directories
# ../components/    - drivers shared with main_hub
set(EXTRA_COMPONENT_DIRS ../components)

# include ESP-IDF build system
include($ENV{IDF_PATH}/tools/cmake/project.cmake)

# project name
project(sentinel_remote_node)