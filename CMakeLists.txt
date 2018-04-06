cmake_minimum_required(VERSION 3.9)
project(UTF-8_Maker)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

aux_source_directory(. DIR)


add_executable(
        UTF-8_Maker

        ${DIR}
)