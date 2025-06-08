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
#include <iostream>

#include "storage/directory.h"
#include "nlohmann/json.hpp"

namespace fs = std::filesystem;
using json = nlohmann::json;

namespace storage {

// Getting the path of the datafile
std::string getDatafile() {
	std::string filePath = storage::getStorageDir() + "/data.jsonc";
	return filePath;
}

// Checking if datafile exists
bool checkForDatafile() {
	std::string filePath = storage::getDatafile();
	if(fs::exists(filePath) && fs::is_regular_file(filePath)) {
		return true;
	}	else {
		return false;
	}
}

// Creating datafile
void createDatafile() {
	std::string filePath = storage::getDatafile();
	std::ofstream outFile(filePath);
	outFile << "[]\n";  // Initialize with an empty JSON array
	outFile.close();
}

// Saving data to the datafile
void saveDatafile(std::string category, std::string value) {
	std::string filePath = storage::getDatafile();
	json datafileObject;

	// Opening the input file
	std::ifstream datafileIn(filePath, std::ios::in);
	if (datafileIn && datafileIn.peek() != std::ifstream::traits_type::eof()) {
		try {
			datafileIn >> datafileObject;
		} catch (const json::parse_error& e) {
			datafileObject = json::array(); // fallback json array if smth goes wrong (which should never happen)
		}
	} else {
		datafileObject = json::array();
	}
	datafileIn.close();

	// Adding to the json array
	datafileObject.push_back({{category, value}});

	// Write the json to the file
	std::ofstream datafileOut(filePath, std::ios::trunc);
	datafileOut << datafileObject.dump(2) << "\n";
	datafileOut.close();
}

// Reads the datafile
std::string readDatafile() {
	std::string filePath = storage::getDatafile();
	std::string processedData;
	std::ifstream inFile(filePath);

	// json Object
	json data;
	inFile >> data;
	inFile.close();

	// Parsing for every value in the json object
	for (const auto& item : data) {
			if (item.is_object()) {
				for (auto it = item.begin(); it != item.end(); ++it) {
					// Append the latest entry to the proccessed data entry
					std::string key = it.key();
					std::transform(key.begin(), key.end(), key.begin(), ::toupper);
					processedData += "\033[1;33m[" + key + "]\033[0m: " + it.value().get<std::string>() + '\n';
				}
			}
		}
	return processedData;
}

}
