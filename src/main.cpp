/*==============================================================================
 * File:        main.cpp
 * Path:        src/
 * Purpose:     Application entry point
 * 
 * Author:      Raphael G. Grubbauer
 * Created:     2025-06-03
 * License:     MIT License
 * Copyright:   (c) 2025 Raphael G. Grubbauer
 *============================================================================*/


#include <algorithm>
#include <iostream>
#include <string>

#include "colorcodes.h"
#include "storage/datafiles.h"
#include "storage/directory.h"

#include "cxxopts/cxxopts.hpp"

constexpr std::string_view VERSION = "0.1.5";

struct LicenseInfo {
	std::string name;
	std::string license;
	std::string url;
};

void verMsg();
void licenseMsg();
void ensureStorageFilesExist();
std::string getInput(const std::string &prompt);

enum ExitCode {
  EXIT_NOERROR = 0,
	EXIT_GENERALERROR = 1,
  EXIT_MISSING_ARGUMENT = 3,
  EXIT_INVALID_ARGUMENT = 4,
  EXIT_EMPTY_INPUT = 5,
};

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cerr << colorcodes::bg::red << colorcodes::bg::black << "Error: No arguments provided.\n"
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

    const auto result = options.parse(argc, argv);

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
                << colorcodes::fg::yellow << "[" << category << "]" << colorcodes::reset << ": "
                << value << "\n";

      storage::saveDatafile(category, value);
    }
    if (result.count("list")) {
      ensureStorageFilesExist();
      std::cout << storage::readDatafile();
    }
    if (result.count("reset")) {
			std::string confirm = getInput("Are you sure you want to delete the datafile? [y/N]: ");
			if (confirm != "y" && confirm != "Y") {
				std::cout << "Aborted.\n";
				return EXIT_NOERROR;
			}

      storage::deleteDatafile();
      std::cout << colorcodes::bg::bright::green << "Deleted datafile.\n" << colorcodes::reset;
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
    std::cerr << colorcodes::bg::red << colorcodes::bg::black << "Error: Unknown option provided. "
              << e.what() << "\n";
    return EXIT_INVALID_ARGUMENT;
  } catch (const std::invalid_argument& e) {
		std::cerr << colorcodes::bg::red << colorcodes::bg::black << e.what() << "\n" << colorcodes::reset;
		return EXIT_EMPTY_INPUT;
	} catch (const std::exception& e) {
		std::cerr << colorcodes::bg::red << colorcodes::bg::black << "Unexpected error: " << e.what() << "\n" << colorcodes::reset;
		return EXIT_GENERALERROR;
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
		std::cout << "This project uses the '" << colorcodes::fg::green << lib.name << colorcodes::reset << "' library, licensed under the " << colorcodes::fg::green << lib.license << colorcodes::reset << " license.\nMore information: " << colorcodes::fg::blue << lib.url << colorcodes::reset << "\n\n";
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

std::string getInput(const std::string &prompt) {
  std::string input;
  std::cout << prompt;
  std::getline(std::cin, input);
  auto isOnlyWhitespace = [](const std::string &s) {
    return std::all_of(s.begin(), s.end(), isspace);
  };
  if (input.empty() || isOnlyWhitespace(input)) {
    throw std::invalid_argument("Input cannot be empty or whitespace.");
  }
  return input;
}
