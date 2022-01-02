#include "Platform/Linux/Events/Events.h"

#include <cstdlib>

namespace KeyPlays::Events {
  void LinuxInputEventHandler::Init() {
    m_Display = XOpenDisplay(NULL);
    if(m_Display == NULL) {
      KP_ERR("Cannot connect to Xorg server!");
      std::exit(-1);
    }

    // Check for X11 extension
    { int queryEvent, queryErr;
      if(!XQueryExtension(m_Display, "XInputExtension", &m_XiCode, &queryEvent, &queryErr)) {
        KP_ERR("X11 Input extension not avaible. Please install libxi-devel.");
        std::exit(-1);
      }
    }

    // Requesting XInput 2.0
    {
      int major = 2, minor = 0;
      int queryRes = XIQueryVersion(m_Display, &major, &minor);
      if(queryRes == BadRequest) {
        KP_ERR("Need XI 2.0 support, got {}.{}!", major, minor);
        std::exit(-1);
      } else if(queryRes != Success) {
        KP_ERR("XIQueryVersion failed!");
        std::exit(-1);
      }
    }
    
    // Register XInput events
    m_RootWindow = DefaultRootWindow(m_Display);
    XIEventMask mask;
    mask.deviceid = XIAllMasterDevices;
    mask.mask_len = XIMaskLen(XI_LASTEVENT);
    mask.mask = (unsigned char *) calloc(mask.mask_len, sizeof(char));
    // Declaring what to look for
    // Using raw key presses + releases
    XISetMask(mask.mask, XI_RawKeyPress);
    XISetMask(mask.mask, XI_RawKeyRelease);

    XISelectEvents(m_Display, m_RootWindow, &mask, 1);
    XSync(m_Display, false);
    free(mask.mask);

    int xkbCode, xkbEventCode;
    // Checking for Xkb extension
    {
      int queryErr, major, minor;
      if(!XkbQueryExtension(m_Display, &xkbCode, &xkbEventCode, &queryErr, &major, &minor)) {
        KP_ERR("Xkb extension not available!");
        std::exit(-1);
      }
    }

    // Registering events
    XkbSelectEventDetails(m_Display, XkbUseCoreKbd, XkbStateNotify, XkbGroupStateMask, XkbGroupStateMask);
    KP_INFO("Initialized event handler for Linux.");
  }
  void LinuxInputEventHandler::CaptureInputs() {
    KP_INFO("Starting to capture input events");

    while(true) {

      // Getting the event
      XEvent event;
      XGenericEventCookie* cookie = &event.xcookie;
      XNextEvent(m_Display, &event);

      if(XGetEventData(m_Display, cookie)) {
        if(cookie->type == GenericEvent && cookie->extension == m_XiCode) {
          XIRawEvent* evt = (XIRawEvent*) cookie->data;
          // Keyboard events
          if(cookie->evtype == XI_RawKeyPress) {
            KP_TRACE("Detected keypress");
            m_DispatchedEvents.push_back(InputEvent(EventType::KeyPressed, evt->detail, Timer::GetCurrentDeltaTime()));
          } else if(cookie->evtype == XI_RawKeyRelease) {
            KP_TRACE("Detected keyrelease");
            m_DispatchedEvents.push_back(InputEvent(EventType::KeyReleased, evt->detail, Timer::GetCurrentDeltaTime()));
          }
        }
      }
    }
    KP_INFO("Stopped capturing events");
  }
} // namespace KeyPlays::Events
