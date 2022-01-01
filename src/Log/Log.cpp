#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace KeyPlays {
  std::shared_ptr<spdlog::logger> Log::s_Logger;

  void Log::Init() {
    s_Logger = spdlog::stdout_color_mt("KeyPlays");
    s_Logger->set_pattern("%^[%T] %n: %v%$");
    s_Logger->set_level(spdlog::level::trace);
  }
} // namespace KeyPlays