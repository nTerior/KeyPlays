#include "Events.h"

namespace KeyPlays::Events {
    IInputEvent::IInputEvent(TimePoint timepoint): m_TimePoint(timepoint) {}
    TimePoint IInputEvent::GetTimePoint() { return m_TimePoint; }

    KeyEvent::KeyEvent(uint32_t keycode, TimePoint timepoint): IInputEvent(timepoint), m_Keycode(keycode) {}
    uint32_t KeyEvent::GetKeyCode() { return m_Keycode; }

    void Init() {
      #ifdef KP_PLATFORM_LINUX
        KP_INFO("Initializing events for linux");
      #endif
    }
} // namespace KeyPlays::Events
