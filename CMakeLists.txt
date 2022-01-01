cmake_minimum_required(VERSION 3.20)

project(KeyPlays VERSION 1.0 LANGUAGES CXX)

add_executable(keyplays)
set_property(TARGET keyplays PROPERTY CXX_STANDARD 20)
target_include_directories(keyplays PUBLIC src)

add_subdirectory(src)
add_subdirectory(vendor)