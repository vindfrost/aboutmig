/* ------------------------------------------------
 * Location: 					src/storage/folder.cpp
 * Purpose:						Source file for folder
  										related storage code.
 * Autor:							Raphael G. Grubbauer
 * Created:						07.06.2025
 * Copyright:					(c) 2025 Raphael G. Grubbauer
 * License:						MIT
 * ------------------------------------------------
*/

#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

bool checkForDirectory(std::string directoryPath) {
	if (fs::exists(directoryPath) && fs::is_directory(directoryPath)) {
		std::cout << "Folder exists\n";
		return true;
	} else {
		std::cout << "Folder does not exist!\n";
		return false;
	}
}
