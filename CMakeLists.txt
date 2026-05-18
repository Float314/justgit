cmake_minimum_required(VERSION 3.15)
project(justgit LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20) # C++17 minimum, C++20 preferred
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(vcmgr INTERFACE)
target_include_directories(vcmgr INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)