/*==============================================================================
 * File:        log.h
 * Path:        include/
 * Purpose:     Logger header for global logging
 *
 * Author:      Raphael G. Grubbauer
 * Created:     2025-06-22
 * License:     MIT
 * Copyright:   (c) 2025 Raphael G. Grubbauer
 *============================================================================*/

#pragma once

#include <memory>
#include <string>

#include "spdlog/logger.h"

std::string getLogDate();
std::shared_ptr<spdlog::logger> get_logger();
