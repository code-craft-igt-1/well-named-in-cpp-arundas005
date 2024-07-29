cmake_minimum_required(VERSION 3.5.0)
project(ColorCoder VERSION 0.1.0 LANGUAGES C CXX)

add_executable(ColorCoder TestColorCoding.cpp ColorPair.cpp ColorNameConstants.cpp ColorCodeUtils.cpp ColorCodePrinter.cpp main.cpp)

