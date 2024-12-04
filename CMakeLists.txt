cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)

project(cli-parser)

add_library(cli-parser STATIC)
file(GLOB_RECURSE CLI_PARSER_SOURCES src/*.cpp)
target_sources(cli-parser PRIVATE ${CLI_PARSER_SOURCES})
target_include_directories(cli-parser PUBLIC include)