/* ------------------------------------------------
 * Location: 					src/storage/directory.cpp
 * Purpose:						Source file for folder
  										related storage code.
 * Autor:							Raphael G. Grubbauer
 * Created:						07.06.2025
 * Copyright:					(c) 2025 Raphael G. Grubbauer
 * License:						MIT
 * ------------------------------------------------
*/

#include <string>

std::string getStorageDir() {
	const std::string home = std::getenv("HOME");
	std::string path = home + ".local/share/aboutmig";

	return path;
}
