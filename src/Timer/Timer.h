#pragma once

#include <chrono>

namespace KeyPlays::Timer {
  static std::chrono::high_resolution_clock globalTimer;
  static std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
  
  // in nanoseconds since last reset
  long GetCurrentDeltaTime();
  void Reset();
} // namespace KeyPlays::Timer
