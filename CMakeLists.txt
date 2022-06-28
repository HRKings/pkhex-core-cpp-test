cmake_minimum_required(VERSION 3.22)
project(PKHex_Cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(PKHex_Cpp src/main.cpp src/save/gen3/gen3_data.h src/utils/utils.h src/utils/utils.cpp src/save/gen3/gen3.cpp src/save/gen3/gen3_utils.h)
