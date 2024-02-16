# Requires at least CMake 3.5
cmake_minimum_required (VERSION 3.5 FATAL_ERROR)

# Header-only library

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

# Create a header-only library (INTERFACE)
# Create alias elk::warningSuppressor so other projects can link to it
add_library(${PROJECT_NAME} INTERFACE)
add_library(elk::warningSuppressor ALIAS ${PROJECT_NAME})

# Specify where the header-only library is
target_include_directories( ${PROJECT_NAME} INTERFACE "${PROJECT_SOURCE_DIR}/include")

# Demo
if (BUILD_DEMO)
    add_subdirectory(Examples)
endif ()