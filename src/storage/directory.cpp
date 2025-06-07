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
#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

std::string getStorageDir() {
	const std::string home = std::getenv("HOME");
	std::string path = home + "/.local/share/aboutmig";

	std::cout << path << "\n";
	return path;
}

bool checkForStorageDir() {
	std::string storageDir = getStorageDir();
	if (fs::exists(storageDir) && fs::is_directory(storageDir)) {
		return true;
	} else {
		return false;
	}
}

void createStorageDir() {
	fs::create_directory(getStorageDir());
	std::cout << "Created directory\n";
}
