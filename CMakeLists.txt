cmake_minimum_required(VERSION 3.10)

project(aes)

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

target_compile_options(aes
PRIVATE
    -std=c++1z
)
