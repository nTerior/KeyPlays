#pragma once

#include "Events/Events.h"

#include <X11/XKBlib.h>
#include <X11/extensions/XInput2.h>

namespace KeyPlays::Events {
  class LinuxInputEventHandler : public IInputEventHandler {
  public:
    void Init() override;
    void CaptureInputs() override;
  private:
    Display *m_Display;
    Window m_RootWindow;
    int m_XiCode;
  };
} // namespace KeyPlays::Events
