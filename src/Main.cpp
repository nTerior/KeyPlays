#include "Events/Events.h"
#include "Window/Window.h"

int main(void) {
  KeyPlays::Log::Init();
  KeyPlays::Events::Init();
  KeyPlays::Window::WindowLoop();
  return 0;
}