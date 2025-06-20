/* ------------------------------------------------
 * Location: 					include/colorcodes.h
 * Purpose:						Storage of ISO/IEC 6429
 *										codes
 * Author:						Raphael G. Grubbauer
 * Created:						19.06.2025
 * Copyright:					(c) 2025 Raphael G. Grubbauer
 * License:						MIT
 * ------------------------------------------------
 */

#ifndef __COLORCODES_H
#define __COLORCODES_H

#include <string_view>

namespace colorcodes {
// Foreground colors (text)
constexpr std::string_view fgBlack = "\x1b[30m";
constexpr std::string_view fgRed = "\x1b[31m";
constexpr std::string_view fgGreen = "\x1b[32m";
constexpr std::string_view fgYellow = "\x1b[33m";
constexpr std::string_view fgBlue = "\x1b[34m";
constexpr std::string_view fgMagenta = "\x1b[35m";
constexpr std::string_view fgCyan = "\x1b[36m";
constexpr std::string_view fgWhite = "\x1b[37m";

// Bright foreground colors
constexpr std::string_view fgBrightBlack = "\x1b[90m";
constexpr std::string_view fgBrightRed = "\x1b[91m";
constexpr std::string_view fgBrightGreen = "\x1b[92m";
constexpr std::string_view fgBrightYellow = "\x1b[93m";
constexpr std::string_view fgBrightBlue = "\x1b[94m";
constexpr std::string_view fgBrightMagenta = "\x1b[95m";
constexpr std::string_view fgBrightCyan = "\x1b[96m";
constexpr std::string_view fgBrightWhite = "\x1b[97m";

// Background colors
constexpr std::string_view bgBlack = "\x1b[40m";
constexpr std::string_view bgRed = "\x1b[41m";
constexpr std::string_view bgGreen = "\x1b[42m";
constexpr std::string_view bgYellow = "\x1b[43m";
constexpr std::string_view bgBlue = "\x1b[44m";
constexpr std::string_view bgMagenta = "\x1b[45m";
constexpr std::string_view bgCyan = "\x1b[46m";
constexpr std::string_view bgWhite = "\x1b[47m";

// Bright background colors
constexpr std::string_view bgBrightBlack = "\x1b[100m";
constexpr std::string_view bgBrightRed = "\x1b[101m";
constexpr std::string_view bgBrightGreen = "\x1b[102m";
constexpr std::string_view bgBrightYellow = "\x1b[103m";
constexpr std::string_view bgBrightBlue = "\x1b[104m";
constexpr std::string_view bgBrightMagenta = "\x1b[105m";
constexpr std::string_view bgBrightCyan = "\x1b[106m";
constexpr std::string_view bgBrightWhite = "\x1b[107m";

// Reset
constexpr std::string_view reset = "\x1b[0m";

}
#endif
