cmake_minimum_required(VERSION 3.10)

project(aes)
set(CMAKE_CXX_STANDARD 17)

add_library(aes "")

target_include_directories(aes
PUBLIC
    include
PRIVATE
    src
)

target_sources(aes
PRIVATE
    src/aes.cpp
)
