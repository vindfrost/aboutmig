/*==============================================================================
 * File:        directory.cpp
 * Path:        src/storage/
 * Purpose:     Handles folder-related storage functionality
 * 
 * Author:      Raphael G. Grubbauer
 * Created:     2025-06-07
 * License:     MIT
 * Copyright:   (c) 2025 Raphael G. Grubbauer
 *============================================================================*/


#include <filesystem>
#include <string>

#include "storage/directory.h"

namespace fs = std::filesystem;

namespace storage {
// Getting the location for the data directory
std::string getStorageDir() {
	const char* homeEnv = std::getenv("HOME");
if (!homeEnv) {
  throw std::runtime_error("HOME environment variable not set.");
}
const std::string home = homeEnv;

  std::string path = home + "/.local/share/aboutmig";

  return path;
}

// Checking if the data directory exists
bool checkForStorageDir() {
	return fs::is_directory(getStorageDir());
}

// Creating the data directory
void createStorageDir() {
	fs::create_directories(getStorageDir());
}
}
