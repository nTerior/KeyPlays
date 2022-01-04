#include "Capture.h"

namespace KeyPlays::Capture {
  std::vector<Events::InputEvent> dispatchedEvents;
  bool recording = false;
  bool playing = false;
} // namespace KeyPlays::Capture