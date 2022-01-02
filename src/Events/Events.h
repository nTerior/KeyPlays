#pragma once

#include <chrono>
#include <cstdint>

namespace KeyPlays::Events {
  typedef std::chrono::time_point<std::chrono::high_resolution_clock> TimePoint;

  // Simple interface class for InputEvents
  // Only contains timepoint, other attribu
  class IInputEvent {
  public:
    IInputEvent(TimePoint timepoint);

    TimePoint GetTimePoint();
  protected:
    TimePoint m_TimePoint;
  };

  class KeyEvent : public IInputEvent {
  public:
    KeyEvent(uint32_t keycode, TimePoint timepoint);

    uint32_t GetKeyCode();
  private:
    uint32_t m_Keycode;
  };

  class IInputEventHandler {
  public:
    IInputEventHandler();
    virtual ~IInputEventHandler();

    // To be done by platform
    virtual void Initialize() = 0;
    virtual void CaptureInputs(std::vector<IInputEvent>* eventList) = 0;
  };

  // Sets the correct InputHandlers per platform
  void Init();
} // namespace KeyPlays::Events