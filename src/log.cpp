/*==============================================================================
 * File:        log.cpp
 * Path:        src/
 * Purpose:     Logger header for global logging
 *
 * Author:      Raphael G. Grubbauer
 * Created:     2025-06-22
 * License:     MIT
 * Copyright:   (c) 2025 Raphael G. Grubbauer
 *============================================================================*/

#include <chrono>
#include <ctime>
#include <iomanip>
#include <string>

#include "log.h"

#include "storage/directory.h"

#include "spdlog/sinks/basic_file_sink.h"

std::string getLogDate() {
  auto now = std::chrono::system_clock::now();
  std::time_t now_time = std::chrono::system_clock::to_time_t(now);
  std::tm *tm_local = std::localtime(&now_time);

  std::ostringstream oss;
  oss << std::put_time(tm_local, "%Y-%m-%d-%H-%M");
  return oss.str();
}

std::shared_ptr<spdlog::logger> get_logger() {
  static std::shared_ptr<spdlog::logger> logger = [] {
    // Damn this is really getting boilerplate
    auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(
      storage::getStorageDir() + "/logs/log-" + getLogDate(), true);
    auto logger = std::make_shared<spdlog::logger>("AboutMig", file_sink);

    logger->set_level(spdlog::level::trace);
    logger->flush_on(spdlog::level::trace);

    return logger;
  }();
  return logger;
}
