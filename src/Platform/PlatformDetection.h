#pragma once

#ifdef _WIN32
  #error "Windows is not supported!"
#elif defined(__APPLE__) || defined(__MACH__)
  #error "macOS is not supported!"
#elif defined(__linux__)
  #define KP_PLATFORM_LINUX
#else
  #error "Unknown platform!"
#endif