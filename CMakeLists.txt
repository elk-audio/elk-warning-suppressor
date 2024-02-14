# Requires at least CMake 3.5
cmake_minimum_required (VERSION 3.5)

##############################
# Project name
##############################
project(elk-warning-suppressor)

##############################
# Setting build options
##############################
option(BUILD_DEMO "Build demo" OFF)

##############################
# Set additional compiler option
##############################
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

##############################
# Add sub directories
##############################

# Header-only library
add_subdirectory(include)

# Demo
if (BUILD_DEMO)
    add_subdirectory(Examples)
endif ()