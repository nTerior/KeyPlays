#include "Platform/Linux/Events/Events.h"

namespace KeyPlays::Events {
  void LinuxInputEventHandler::Init() {
    KP_INFO("Initialized events for Linux.");
  }
  void LinuxInputEventHandler::CaptureInputs() {
    KP_INFO("Starting to capture input events");
  }
} // namespace KeyPlays::Events
