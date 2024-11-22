cmake_minimum_required(VERSION 3.28)
project(FileManager_Cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(FileManager main.cpp
        File.h
        Directory.h
        SearchEngine.h
        UserInterface.h
        FileManager.h)
