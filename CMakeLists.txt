cmake_minimum_required(VERSION 3.20)

# Setup vcpkg script with CMake (note: should be placed before project() call)
set(VCPKG_ROOT "${CMAKE_CURRENT_LIST_DIR}/tools/vcpkg")
set(CMAKE_TOOLCHAIN_FILE
    "${VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
    CACHE STRING "Vcpkg toolchain file")

project(tree_visibility)

# Tree visibility application options
option(TREE_VISIBILITY_BUILD_APP "Build the application" ON)
option(TREE_VISIBILITY_BUILD_TEST "Build the tests" ON)

if(PROJECT_IS_TOP_LEVEL)
  # Export compile commands for clang-tidy
  set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
  set(CMAKE_VERBOSE_MAKEFILE ON)

  # Set language standard
  set(CMAKE_CXX_STANDARD 11)
endif()

# Create library
add_library(${PROJECT_NAME})

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/cmd/lib"
             LIBRARY_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/cmd/lib")

target_include_directories(${PROJECT_NAME}
                           PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Add subdirectories for main source code and tests
add_subdirectory(src)
