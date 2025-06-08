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
#include <fstream>

#include "storage/directory.h"
#include "nlohmann/json.hpp"

namespace fs = std::filesystem;
using json = nlohmann::json;

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

void createDatafile() {
	std::string filePath = storage::getDatafile();
	std::ofstream outFile(filePath);
	outFile << "[]\n";  // Initialize with an empty JSON array
	outFile.close();
}


void saveDatafile(std::string category, std::string value) {
	std::string filePath = storage::getDatafile();
	json datafileObject;

	std::ifstream datafileIn(filePath, std::ios::in);
	if (datafileIn && datafileIn.peek() != std::ifstream::traits_type::eof()) {
		try {
			datafileIn >> datafileObject;
		} catch (const json::parse_error& e) {
			datafileObject = json::array();
		}
	} else {
		datafileObject = json::array();
	}
	datafileIn.close();

	datafileObject.push_back({{category, value}});

	std::ofstream datafileOut(filePath, std::ios::trunc);
	datafileOut << datafileObject.dump(2) << "\n";
	datafileOut.close();
}


}
