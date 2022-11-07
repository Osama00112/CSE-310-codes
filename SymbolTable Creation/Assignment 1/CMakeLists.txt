cmake_minimum_required(VERSION 3.15)
project(Assignment_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment_1
        hash.h
        Main.cpp
        random.h
        SymbolInfo.h ScopeTable.h SymbolTable.h)
