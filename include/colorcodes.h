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

namespace colorcode{
// Basic colors
const std::string Black					= "\x1b[30m";
const std::string Red						= "\x1b[31m";
const std::string Green					= "\x1b[32m";
const std::string Yellow				= "\x1b[33m";
const std::string Blue					= "\x1b[34m";
const std::string Magenta				= "\x1b[35m";
const std::string Cyan					= "\x1b[36m";
const std::string White					= "\x1b[37m";

// Bright colors
const std::string BrightBlack   = "\x1b[90m";
const std::string BrightRed     = "\x1b[91m";
const std::string BrightGreen   = "\x1b[92m";
const std::string BrightYellow  = "\x1b[93m";
const std::string BrightBlue    = "\x1b[94m";
const std::string BrightMagenta = "\x1b[95m";
const std::string BrightCyan    = "\x1b[96m";
const std::string BrightWhite   = "\x1b[97m";

// Reset
const std::string Reset					= "\x1b[0m";
}
#endif
