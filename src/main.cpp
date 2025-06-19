/* ------------------------------------------------
 * Location: 					src/main.cpp
 * Purpose:						Main source file
 * Author:						Raphael G. Grubbauer
 * Created:						03.06.2025
 * Copyright:					(c) 2025 Raphael G. Grubbauer
 * License:						MIT
 * ------------------------------------------------
 */

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>

#include "storage/datafiles.h"
#include "storage/directory.h"

#include "cxxopts/cxxopts.hpp"

constexpr std::string_view VERSION = "0.1.1";

constexpr int EXIT_MISSING_ARGUMENT = 3;
constexpr int EXIT_INVALID_ARGUMENT = 4;
constexpr int EXIT_EMPTY_INPUT = 5;

void verMsg();
void licenseMsg();
void checkFiles();
std::string getCategory();
std::string getValue();

int main(int argc, char *argv[])
{
  // ANSI escape codes
  const std::string ANSI_bold_yellow = "\033[1;33m";
  const std::string ANSI_reset = "\033[0m";

	if (argc == 1) {
		std::cerr << "Error: No arguments provided.\n";
		return EXIT_MISSING_ARGUMENT;
	}

try {
	cxxopts::Options options("aboutmig", "Cross-platform software to add information about yourself. Version " + std::string(VERSION));


	options.add_options()
		("h,help", "Print helper text.")
		("a,add", "Add information.")
		("l,list", "List all currently stored information.")
		("r,reset", "Reset datafile.")
		("L,license", "List all licenses.")
		("v,version", "Print version.");
	
	auto result = options.parse(argc, argv);

	if (result.count("help")) {
		std::cout << options.help() << "\n";
		return EXIT_SUCCESS;
	}
	if (result.count("add")) {
		checkFiles();

		// Display welcome messsage
    std::string category;
    std::string value;

    category = getCategory();
    std::transform(category.begin(), category.end(), category.begin(), ::toupper);
    value = getValue();

    std::cout << "\nYou entered:\n"
              << ANSI_bold_yellow << "[" << category << "]" << ANSI_reset << ": " << value << "\n";

    storage::saveDatafile(category, value);
	}
	if (result.count("list")){
		std::cout << storage::readDatafile();
	}
	if (result.count("reset")) {
		storage::deleteDatafile();
		std::cout << "Deleted datafile.\n";
	}
	if (result.count("version")) {
		verMsg();
		return EXIT_SUCCESS;
	}
	if (result.count("license")) {
		licenseMsg();
		return EXIT_SUCCESS;
	}
} catch (cxxopts::exceptions::no_such_option& e) {
	std::cerr << "Error: Unknown option provided. " << e.what() << "\n";
	return EXIT_INVALID_ARGUMENT;
}

	return EXIT_SUCCESS;
}

// Displaying version
void verMsg()
{
  std::cout << "AboutMig " << VERSION << "\n";
}

void licenseMsg() {
  std::cout
    << "This project uses the 'nlohmann' JSON library, which is licensed under the MIT license.\n";
  std::cout << "More information about the library can be found at:\n";
  std::cout << "https://github.com/nlohmann/json/\n\n";

	std::cout << "This project uses the 'cxxopts' header, which is licensed under the MIT license.\n";
	std::cout << "More information about the header can be found at:\n";
	std::cout << "https://github.com/jarro2783/cxxopts/\n";
}

void checkFiles() {
	  if (storage::checkForStorageDir() == false) {
    storage::createStorageDir();
  }
  if (storage::checkForDatafile() == false) {
    storage::createDatafile();
  }

}

// Getting the category
std::string getCategory()
{
  std::string category;
  std::cout << "Enter category: ";
  std::getline(std::cin, category);
  auto isOnlyWhitespace = [](const std::string &s) {
    return std::all_of(s.begin(), s.end(), isspace);
  };
  if (category.empty() || isOnlyWhitespace(category)) {
    std::cerr << "Category cannot be empty.\n";
    exit(EXIT_EMPTY_INPUT);
  }
  return category;
}

// Getting the value
std::string getValue()
{
  std::string value;
  std::cout << "Enter value: ";
  std::getline(std::cin, value);
  auto isOnlyWhitespace = [](const std::string &s) {
    return std::all_of(s.begin(), s.end(), isspace);
  };
  if (value.empty() || isOnlyWhitespace(value)) {
    std::cerr << "Value cannot be empty.\n";
    exit(EXIT_EMPTY_INPUT);
  }
  return value;
}
