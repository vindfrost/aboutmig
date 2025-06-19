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
const std::string black					= "\x1b[30m";
const std::string red						= "\x1b[31m";
const std::string green					= "\x1b[32m";
const std::string yellow				= "\x1b[33m";
const std::string blue					= "\x1b[34m";
const std::string magenta				= "\x1b[35m";
const std::string cyan					= "\x1b[36m";
const std::string white					= "\x1b[37m";

// Bright colors
const std::string brightBlack   = "\x1b[90m";
const std::string brightRed     = "\x1b[91m";
const std::string brightGreen   = "\x1b[92m";
const std::string brightYellow  = "\x1b[93m";
const std::string brightBlue    = "\x1b[94m";
const std::string brightMagenta = "\x1b[95m";
const std::string brightCyan    = "\x1b[96m";
const std::string brightWhite   = "\x1b[97m";

// Reset
const std::string Reset					= "\x1b[0m";
}
#endif
