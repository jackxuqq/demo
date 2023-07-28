cmake_minimum_required(VERSION 3.10)

project(main)

# Abseil requires C++14
set(CMAKE_CXX_STANDARD 14)

# Process Abseil's CMake build system
add_subdirectory(abseil-cpp)

add_executable(main main.cpp)

# Declare dependency on the absl::strings library
target_link_libraries(main absl::strings absl::flat_hash_map)
