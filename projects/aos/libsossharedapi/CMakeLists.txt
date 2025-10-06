cmake_minimum_required(VERSION 3.7.2)

project(libsossharedapi C)

add_library(
    sossharedapi INTERFACE
)
target_include_directories(sossharedapi INTERFACE include)
