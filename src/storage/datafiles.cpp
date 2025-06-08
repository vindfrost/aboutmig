/* ------------------------------------------------
 * Location: 					src/storage/datafiles.cpp
 * Purpose:						Source file for datafiles
  										related storage code.
 * Autor:							Raphael G. Grubbauer
 * Created:						07.06.2025
 * Copyright:					(c) 2025 Raphael G. Grubbauer
 * License:						MIT
 * ------------------------------------------------
*/
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

#include "storage/directory.h"

namespace storage {

std::string getDatafile() {
	std::string filePath = storage::getStorageDir() + "/data.jsonc";
	return filePath;
}

bool checkForDatafile() {
	std::string filePath = storage::getDatafile();
	if(fs::exists(filePath) && fs::is_regular_file(filePath)) {
		return true;
	}	else {
		return false;
	}
}

}
