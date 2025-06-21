/*==============================================================================
 * File:        datafiles.cpp
 * Path:        src/storage/
 * Purpose:     Handles datafile-related storage functionality
 * 
 * Author:      Raphael G. Grubbauer
 * Created:     2025-06-07
 * License:     MIT
 * Copyright:   (c) 2025 Raphael G. Grubbauer
 *============================================================================*/

#include <cstdio>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

#include "colorcodes.h"
#include "storage/datafiles.h"
#include "storage/directory.h"

#include "nlohmann/json.hpp"

namespace fs = std::filesystem;
using json = nlohmann::json;

namespace storage {

// Getting the path of the datafile
std::string getDatafile() {
  std::string filePath = getStorageDir() + "/data.json";
  return filePath;
}

// Checking if datafile exists
bool checkForDatafile() {
	return fs::is_regular_file(getDatafile());
}

// Creating datafile
void createDatafile() {
  std::string filePath = getDatafile();
  std::ofstream outFile(filePath);
	if (!outFile) {
		throw std::runtime_error("Failed to create datafile: " + filePath);
	} 
  outFile << "[]\n";  // Initialize with an empty JSON array
  outFile.close();
}

// Saving data to the datafile
void saveDatafile(std::string category, std::string value) {
  std::string filePath = getDatafile();
  json datafileObject;

  // Opening the input file
  std::ifstream datafileIn(filePath, std::ios::in);
  if (datafileIn && datafileIn.peek() != std::ifstream::traits_type::eof()) {
    try {
      datafileIn >> datafileObject;
    } catch (const json::parse_error &e) {
      datafileObject =
        json::array();  // fallback json array if smth goes wrong (which should never happen)
    }
  } else {
    datafileObject = json::array();
  }
  datafileIn.close();

  // Adding to the json array
  datafileObject.push_back({{("[" + category + "]"), value}});

  // Write the json to the file
  std::ofstream datafileOut(filePath, std::ios::trunc);
  datafileOut << datafileObject.dump(2) << "\n";
  datafileOut.close();
}

// Reads the datafile
std::string readDatafile() {
  std::string filePath = getDatafile();
  std::string processedData;
  std::ifstream inFile(filePath);

  // json Object
  json data;
  inFile >> data;
  inFile.close();

  // Parsing each entry in the JSON array
  for (const auto &item : data) {
    if (item.is_object()) {
      for (auto it = item.begin(); it != item.end(); ++it) {
        // Append the latest entry to the proccessed data entry
        std::string key = it.key();
				processedData +=
    std::string(colorcodes::fg::yellow) + key + std::string(colorcodes::reset) + ":" +
    it.value().get<std::string>() + '\n';

      }
    }
  }
  return processedData;
}

void deleteDatafile() {
  std::string filePath = getDatafile();
  std::remove(filePath.c_str());
}
}
