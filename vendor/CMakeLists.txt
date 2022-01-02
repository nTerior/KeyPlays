# Libraries
# -- spdlog --
add_subdirectory(spdlog)
target_include_directories(keyplays PUBLIC spdlog/include)
target_link_libraries(keyplays PUBLIC spdlog)

# -- glfw --
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(glfw)
target_include_directories(keyplays PUBLIC glfw/include)
target_link_libraries(keyplays PUBLIC glfw)
find_package(OpenGL REQUIRED)
target_link_libraries(keyplays PUBLIC OpenGL::GL)

# -- ImGui --
target_include_directories(keyplays PUBLIC imgui imgui/backends)
target_sources(keyplays PUBLIC
  imgui/imgui.cpp
  imgui/imgui_demo.cpp
  imgui/imgui_draw.cpp
  imgui/imgui_tables.cpp
  imgui/imgui_widgets.cpp
  imgui/backends/imgui_impl_glfw.cpp
  imgui/backends/imgui_impl_opengl3.cpp
)
target_link_libraries(keyplays PUBLIC dl)