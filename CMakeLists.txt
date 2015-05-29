cmake_minimum_required(VERSION 2.8)
project(FifoTest)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package (Threads)

set(SOURCE_FILES main.cpp)
add_executable(FifoTest ${SOURCE_FILES} Fifo.h MemBlock.h)
target_link_libraries (FifoTest ${CMAKE_THREAD_LIBS_INIT})