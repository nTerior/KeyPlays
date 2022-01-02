#include "Events/Events.h"

#ifdef KP_PLATFORM_LINUX
  #include "Platform/Linux/Events/Events.h"
#else
  #error "Platform not supported"
#endif

#include <thread>

namespace KeyPlays::Events {
  InputEvent::InputEvent(EventType type, uint32_t data, long timepoint): m_Type(type), m_Data(data), m_TimePoint(timepoint) {}
  EventType InputEvent::GetEventType() { return m_Type; }
  uint32_t InputEvent::GetData() { return m_Data; }
  long InputEvent::GetTimePoint() { return m_TimePoint; }

  std::vector<InputEvent> IInputEventHandler::GetDispatchedEvents() { return m_DispatchedEvents; }
  void IInputEventHandler::ClearDispatchedEvents() { m_DispatchedEvents.clear(); }

  void Init() {
    #ifdef KP_PLATFORM_LINUX
    KP_INFO("Initializing event handler for Linux.");
    LinuxInputEventHandler* evtHandler = new LinuxInputEventHandler();
    // For other platforms:
    /*
    #elif defined(KP_PLATFORM_{platform})
    KP_INFO("Initializing event handler for {Platform}.");
    {Platform}InputEventHandler* evtHandler = new {Platform}InputEventHandler();
    */
    // It is **IMPORTANT** to name your created InputEventHandler variable **EXACTLY** evtHandler !!!
    #endif

    evtHandler->Init();
    std::thread thread(&IInputEventHandler::CaptureInputs, evtHandler);
    thread.detach();
  }
} // namespace KeyPlays::Events
