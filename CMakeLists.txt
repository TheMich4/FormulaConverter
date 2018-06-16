cmake_minimum_required(VERSION 3.10)
project(FormulaConverter)

set(CMAKE_CXX_STANDARD 17)

add_executable(FormulaConverter main.cpp Converter.cpp Converter.h TruthColumn.cpp TruthColumn.h)