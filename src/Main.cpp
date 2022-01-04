#include "Events/Events.h"
#include "Window/Window.h"
#include "Timer/Timer.h"

int main(void) {
  KeyPlays::Timer::Reset();
  KeyPlays::Log::Init();
  KeyPlays::Events::Init();
  KeyPlays::Window::WindowLoop();
  return 0;
}