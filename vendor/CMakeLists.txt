# Libraries
# -- spdlog --

add_subdirectory(spdlog)

target_include_directories(keyplays PUBLIC spdlog/include)
target_link_libraries(keyplays PUBLIC spdlog)