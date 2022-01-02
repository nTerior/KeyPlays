#include "Events/Events.h"

int main(void) {
  KeyPlays::Log::Init();
  KeyPlays::Events::Init();
  for(;;);
  return 0;
}