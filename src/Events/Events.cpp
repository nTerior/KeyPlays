#include "Events/Events.h"
#include "Capture/Capture.h"

#include <thread>

namespace KeyPlays::Events {
  InputEvent::InputEvent(EventType type, uint32_t data, long timepoint): m_Type(type), m_Data(data), m_TimePoint(timepoint) {}
  EventType InputEvent::GetEventType() { return m_Type; }
  uint32_t InputEvent::GetData() { return m_Data; }
  long InputEvent::GetTimePoint() { return m_TimePoint; }

  void Init() {
    // Setting the event handler: Capture/Capture.h
    Capture::eventHandler.Init();
    
    std::thread thread(&IInputEventHandler::CaptureInputs, Capture::eventHandler);
    thread.detach();
  }
} // namespace KeyPlays::Events
