# Checking for compatible platforms
if (CMAKE_SYSTEM_NAME MATCHES "Linux")
  message("Using Platform Linux")
  target_sources(keyplays PUBLIC
    Linux/Events/Events.cpp
  )
endif()