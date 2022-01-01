#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

#include <memory>

namespace KeyPlays {
  class Log {
  public:
    static void Init();
    inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_Logger; }
  private:
    static std::shared_ptr<spdlog::logger> s_Logger;
  }; // class Log
} // namespace KeyPlays

// Logging makros
#define KP_TRACE(...) KeyPlays::Log::GetLogger()->trace(__VA_ARGS__)
#define KP_INFO(...) KeyPlays::Log::GetLogger()->info(__VA_ARGS__)
#define KP_WARN(...) KeyPlays::Log::GetLogger()->warn(__VA_ARGS__)
#define KP_ERR(...) KeyPlays::Log::GetLogger()->error(__VA_ARGS__)
#define KP_CRITICAL(...)KeyPlays::Log::GetLogger()->critical(__VA_ARGS__) 