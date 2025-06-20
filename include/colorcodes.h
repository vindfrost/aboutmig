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

#include <string>

namespace colorcodes {
// Foreground colors (text)
const std::string fgBlack = "\x1b[30m";
const std::string fgRed = "\x1b[31m";
const std::string fgGreen = "\x1b[32m";
const std::string fgYellow = "\x1b[33m";
const std::string fgBlue = "\x1b[34m";
const std::string fgMagenta = "\x1b[35m";
const std::string fgCyan = "\x1b[36m";
const std::string fgWhite = "\x1b[37m";

// Bright foreground colors
const std::string fgBrightBlack = "\x1b[90m";
const std::string fgBrightRed = "\x1b[91m";
const std::string fgBrightGreen = "\x1b[92m";
const std::string fgBrightYellow = "\x1b[93m";
const std::string fgBrightBlue = "\x1b[94m";
const std::string fgBrightMagenta = "\x1b[95m";
const std::string fgBrightCyan = "\x1b[96m";
const std::string fgBrightWhite = "\x1b[97m";

// Background colors
const std::string bgBlack = "\x1b[40m";
const std::string bgRed = "\x1b[41m";
const std::string bgGreen = "\x1b[42m";
const std::string bgYellow = "\x1b[43m";
const std::string bgBlue = "\x1b[44m";
const std::string bgMagenta = "\x1b[45m";
const std::string bgCyan = "\x1b[46m";
const std::string bgWhite = "\x1b[47m";

// Bright background colors
const std::string bgBrightBlack = "\x1b[100m";
const std::string bgBrightRed = "\x1b[101m";
const std::string bgBrightGreen = "\x1b[102m";
const std::string bgBrightYellow = "\x1b[103m";
const std::string bgBrightBlue = "\x1b[104m";
const std::string bgBrightMagenta = "\x1b[105m";
const std::string bgBrightCyan = "\x1b[106m";
const std::string bgBrightWhite = "\x1b[107m";

// Reset
const std::string reset = "\x1b[0m";

}
#endif
