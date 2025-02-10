# Requires at least CMake 3.5
cmake_minimum_required (VERSION 3.5 FATAL_ERROR)

# Header-only library

##############################
# Project name
##############################

set(ELK_WARNING_SUPPRESSOR_VERSION_MAJOR 0)
set(ELK_WARNING_SUPPRESSOR_VERSION_MINOR 1)
set(ELK_WARNING_SUPPRESSOR_VERSION_REVISION 0)

project(elk-warning-suppressor
        DESCRIPTION "Cross-platform, header-only library to help suppress warnings in included 3rd party's code"
        HOMEPAGE_URL "https://github.com/elk-audio/elk-warning-suppressor"
        LANGUAGES CXX
        VERSION ${ELK_WARNING_SUPPRESSOR_VERSION_MAJOR}.${ELK_WARNING_SUPPRESSOR_VERSION_MINOR}.${ELK_WARNING_SUPPRESSOR_VERSION_REVISION}
)

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
target_include_directories(${PROJECT_NAME} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include/elk-warning-suppressor>
)

set_target_properties(${PROJECT_NAME}
    PROPERTIES EXPORT_NAME warningSuppressor
)
# Demo
if (BUILD_DEMO)
    add_subdirectory(Examples)
endif ()

#############
#  Install  #
#############

# Create install target for library
install(TARGETS ${PROJECT_NAME}
        EXPORT elkWarningSuppressorConfig
        PUBLIC_HEADER DESTINATION include/elk-warning-suppressor
)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/elk-warning-suppressor DESTINATION include)

# Generate config version file
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        ${CMAKE_CURRENT_BINARY_DIR}/elk-warning-suppressorConfigVersion.cmake
        VERSION ${ELK_WARNING_SUPPRESSOR_VERSION_MAJOR}.${ELK_WARNING_SUPPRESSOR_VERSION_MINOR}.${ELK_WARNING_SUPPRESSOR_VERSION_REVISION}
        COMPATIBILITY SameMinorVersion
)

# Generate install config file
install(EXPORT elkWarningSuppressorConfig
        FILE elk-warning-suppressorConfig.cmake
        DESTINATION lib/cmake/elk-warning-suppressor
        NAMESPACE elk::
)


# Install config version file
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/elk-warning-suppressorConfigVersion.cmake
      DESTINATION lib/cmake/elk-warning-suppressor
)

