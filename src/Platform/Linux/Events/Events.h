#pragma once

#include "Events/Events.h"

namespace KeyPlays::Events {
  class LinuxInputEventHandler : public IInputEventHandler {
  public:
    void Init() override;
    void CaptureInputs() override;
  };
} // namespace KeyPlays::Events
