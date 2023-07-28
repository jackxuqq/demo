cmake_minimum_required(VERSION 2.8)
project(astToPB)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

include_directories("../thirty_party/rapidjson/include/" "inc")

aux_source_directory(. main_src)
add_executable(${PROJECT_NAME} ${main_src})
