/*==============================================================================
 * File:        colorcodes.h
 * Path:        include/
 * Purpose:     Storage of ISO/IEC 6429 escape code sequences
 * 
 * Author:      Raphael G. Grubbauer
 * Created:     2025-06-19
 * License:     MIT
 * Copyright:   (c) 2025 Raphael G. Grubbauer
 *============================================================================*/

#pragma once

#include <string_view>

namespace colorcodes {
	namespace fg {
// Foreground colors (text)
constexpr std::string_view black = "\x1b[30m";
constexpr std::string_view red = "\x1b[31m";
constexpr std::string_view green = "\x1b[32m";
constexpr std::string_view yellow = "\x1b[33m";
constexpr std::string_view blue = "\x1b[34m";
constexpr std::string_view magenta = "\x1b[35m";
constexpr std::string_view cyan = "\x1b[36m";
constexpr std::string_view white = "\x1b[37m";

namespace bright {
// Bright foreground colors
constexpr std::string_view black = "\x1b[90m";
constexpr std::string_view red = "\x1b[91m";
constexpr std::string_view green = "\x1b[92m";
constexpr std::string_view yellow = "\x1b[93m";
constexpr std::string_view blue = "\x1b[94m";
constexpr std::string_view magenta = "\x1b[95m";
constexpr std::string_view cyan = "\x1b[96m";
constexpr std::string_view white = "\x1b[97m";
}
}

namespace bg {
// Background colors
constexpr std::string_view black = "\x1b[40m";
constexpr std::string_view red = "\x1b[41m";
constexpr std::string_view green = "\x1b[42m";
constexpr std::string_view yellow = "\x1b[43m";
constexpr std::string_view blue = "\x1b[44m";
constexpr std::string_view magenta = "\x1b[45m";
constexpr std::string_view cyan = "\x1b[46m";
constexpr std::string_view white = "\x1b[47m";

namespace bright {
// Bright background colors
constexpr std::string_view black = "\x1b[100m";
constexpr std::string_view red = "\x1b[101m";
constexpr std::string_view green = "\x1b[102m";
constexpr std::string_view yellow = "\x1b[103m";
constexpr std::string_view blue = "\x1b[104m";
constexpr std::string_view magenta = "\x1b[105m";
constexpr std::string_view cyan = "\x1b[106m";
constexpr std::string_view white = "\x1b[107m";
}
}
// Reset
constexpr std::string_view reset = "\x1b[0m";

}
