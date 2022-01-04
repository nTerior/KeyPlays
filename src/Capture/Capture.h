#pragma once

#ifdef KP_PLATFORM_LINUX
  #include "Platform/Linux/Events/Events.h"
#else
  #error "Platform not supported"
#endif

#include <atomic>

namespace KeyPlays::Capture {
  // Event Handler
  static Events::
  #ifdef KP_PLATFORM_LINUX
  LinuxInputEventHandler
  // For each other platforms:
  /*
  #elif defined(KP_PLATFORM_{PLATFORM})
  {PlatformInputEventHandler}
  */
  // Therefore, {Platform}InputEventHandler has to be in the KeyPlays::Events namespace
  #endif
  eventHandler;

  extern std::vector<Events::InputEvent> dispatchedEvents;

  extern bool recording;
  extern bool playing;
} // namespace KeyPlays::Capture
