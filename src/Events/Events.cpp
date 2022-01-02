#include "Events/Events.h"

#ifdef KP_PLATFORM_LINUX
  #include "Platform/Linux/Events/Events.h"
#else
  #error "Platform not supported"
#endif

namespace KeyPlays::Events {
  IInputEvent::IInputEvent(TimePoint timepoint): m_TimePoint(timepoint) {}
  TimePoint IInputEvent::GetTimePoint() { return m_TimePoint; }

  KeyEvent::KeyEvent(uint32_t keycode, TimePoint timepoint): IInputEvent(timepoint), m_Keycode(keycode) {}
  uint32_t KeyEvent::GetKeyCode() { return m_Keycode; }

  KeyPressedEvent::KeyPressedEvent(uint32_t keycode, TimePoint timepoint): KeyEvent(keycode, timepoint) {}
  KeyReleasedEvent::KeyReleasedEvent(uint32_t keycode, TimePoint timepoint): KeyEvent(keycode, timepoint) {}

  std::vector<IInputEvent> IInputEventHandler::GetDispatchedEvents() { return m_DispatchedEvents; }
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
