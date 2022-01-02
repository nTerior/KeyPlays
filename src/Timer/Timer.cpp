#include "Timer.h"

namespace KeyPlays::Timer {
  
  long GetCurrentDeltaTime() {
    return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - startTime).count();
  }

  void Reset() {
    startTime = globalTimer.now();
  }
} // namespace KeyPlays::Timer