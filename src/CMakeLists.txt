target_sources(keyplays PUBLIC
  Main.cpp
  Log/Log.cpp
  Events/Events.cpp
  Window/Window.cpp
)

target_precompile_headers(keyplays PUBLIC keyplays.h)

add_subdirectory(Platform)