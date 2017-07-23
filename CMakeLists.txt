cmake_minimum_required(VERSION 2.8)
project(ash)

set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -D_GLIBCXX_DEBUG -DASH_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -flto -DNDEBUG")
set(CMAKE_CXX_FLAGS "-std=c++14 -Wall -Wextra -Wshadow")

file(GLOB_RECURSE ENGINE_SRC "src/*.cpp" "headers/*.hpp" "headers/*.inl")
add_library(ash STATIC ${ENGINE_SRC})
target_include_directories(ash PUBLIC "headers")
