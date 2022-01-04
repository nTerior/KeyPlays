#pragma once

#include "Timer/Timer.h"

#include <chrono>
#include <cstdint>

namespace KeyPlays::Events {
  
  enum EventType {
    KeyPressed = 0,
    KeyReleased,
    MousePressed,
    MouseReleased
  };

  class InputEvent {
  public:
    InputEvent(EventType type, uint32_t data, long timepoint);

    EventType GetEventType();
    // Returns keycode if KeyPressed/-Released or mouse button
    uint32_t GetData();
    long GetTimePoint();
  protected:
    EventType m_Type;
    uint32_t m_Data;
    long m_TimePoint;
  };

  class IInputEventHandler {
  public:
    virtual void Init() = 0;
    virtual void CaptureInputs() = 0;
  };

  // Sets the correct InputHandlers per platform
  void Init();
} // namespace KeyPlays::Events