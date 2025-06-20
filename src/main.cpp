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
#include <iostream>
#include <string>

#include "colorcodes.h"
#include "storage/datafiles.h"
#include "storage/directory.h"

#include "cxxopts/cxxopts.hpp"

constexpr std::string_view VERSION = "0.1.4";

struct LicenseInfo {
	std::string name;
	std::string license;
	std::string url;
};

void verMsg();
void licenseMsg();
void ensureStorageFilesExist();
std::string getInput(const std::string &prompt);
static bool isOnlyWhitespace(const std::string &s);

enum ExitCode {
  EXIT_NOERROR = 1,
  EXIT_MISSING_ARGUMENT = 3,
  EXIT_INVALID_ARGUMENT = 4,
  EXIT_EMPTY_INPUT = 5,
};

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cerr << colorcodes::bgRed << colorcodes::fgBlack << "Error: No arguments provided.\n"
              << colorcodes::reset;
    return EXIT_MISSING_ARGUMENT;
  }

  try {
    cxxopts::Options options("aboutmig",
                             "Cross-platform software to add information about yourself. Version " +
                               std::string(VERSION));

    options.add_options()("h,help", "Print helper text.")("a,add", "Add information.")(
      "l,list", "List all currently stored information.")("r,reset", "Reset datafile.")(
      "L,license", "List all licenses.")("v,version", "Print version.");

    auto result = options.parse(argc, argv);

    if (result.count("help")) {
      std::cout << options.help() << "\n";
      return EXIT_NOERROR;
    }
    if (result.count("add")) {
      ensureStorageFilesExist();

      std::string category = getInput("Enter category: ");
      std::transform(category.begin(), category.end(), category.begin(), ::toupper);
      std::string value = getInput("Enter value: ");

      std::cout << "\nYou entered:\n"
                << colorcodes::fgYellow << "[" << category << "]" << colorcodes::reset << ": "
                << value << "\n";

      storage::saveDatafile(category, value);
    }
    if (result.count("list")) {
      ensureStorageFilesExist();
      std::cout << storage::readDatafile();
    }
    if (result.count("reset")) {
      storage::deleteDatafile();
      std::cout << colorcodes::fgBrightGreen << "Deleted datafile.\n" << colorcodes::reset;
    }
    if (result.count("version")) {
      verMsg();
      return EXIT_NOERROR;
    }
    if (result.count("license")) {
      licenseMsg();
      return EXIT_NOERROR;
    }
  } catch (cxxopts::exceptions::no_such_option &e) {
    std::cerr << colorcodes::bgRed << colorcodes::fgBlack << "Error: Unknown option provided. "
              << e.what() << "\n";
    return EXIT_INVALID_ARGUMENT;
  } catch (const std::invalid_argument& e) {
		std::cerr << colorcodes::bgRed << colorcodes::fgBlack << e.what() << "\n" << colorcodes::reset;	
	}

  return EXIT_NOERROR;
}

// Displaying version
void verMsg() {
  std::cout << "AboutMig " << VERSION << "\n";
}

const std::vector<LicenseInfo> licenses = {
	{"nlohmann JSON", "MIT", "https://github.com/nlohmann/json/"},
	{"cxxopts", "MIT", "https://github.com/jarro2783/cxxopts/"}
};

void licenseMsg() {
	for (const auto& lib : licenses) {
		std::cout << "This project uses the '" << colorcodes::fgGreen << lib.name << colorcodes::reset << "' library, licensed under the " << colorcodes::fgGreen << lib.license << colorcodes::reset << " license.\nMore information: " << colorcodes::fgBlue << lib.url << colorcodes::reset << "\n\n";
	}
}

void ensureStorageFilesExist() {
  if (storage::checkForStorageDir() == false) {
    storage::createStorageDir();
  }
  if (storage::checkForDatafile() == false) {
    storage::createDatafile();
  }
}

static bool isOnlyWhitespace(const std::string &s) {
  return std::all_of(s.begin(), s.end(), isspace);
}

std::string getInput(const std::string &prompt) {
  std::string input;
  std::cout << prompt;
  std::getline(std::cin, input);
  if (input.empty() || isOnlyWhitespace(input)) {
		throw std::invalid_argument("Input cannot be empty or whitespace.");
  }
  return input;
}
