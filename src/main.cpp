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

#include "storage/datafiles.h"
#include "storage/directory.h"

constexpr std::string_view VERSION = "0.1.0";

constexpr int EXIT_MISSING_ARGUMENT = 3;
constexpr int EXIT_INVALID_ARGUMENT = 4;
constexpr int EXIT_EMPTY_INPUT = 5;

void helpMsg();
void verMsg();
std::string getCategory();
std::string getValue();

int main(int argc, char *argv[])
{
  // Argument values
  bool do_list = false;
  bool do_add = false;
  bool do_reset = false;
  bool do_help = false;
  bool do_version = false;

  // ANSI escape codes
  const std::string ANSI_bold_yellow = "\033[1;33m";
  const std::string ANSI_reset = "\033[0m";

  for (int i = 1; i < argc; ++i) {
    const char *arg = argv[i];

    // Check if argument starts with a dash
    if (arg[0] == '-') {
      for (int j = 1; arg[j] != '\0'; ++j) {
        switch (arg[j]) {
          case 'l':
            do_list = true;
            break;
          case 'a':
            do_add = true;
            break;
          case 'r':
            do_reset = true;
            break;
          case 'h':
            do_help = true;
            break;
          case 'v':
            do_version = true;
            break;
          default:
            std::cerr << "Unknown option: -" << arg[j] << ".\n";
            std::cout << "More info with \"aboutmig -h\".\n";
            return EXIT_INVALID_ARGUMENT;
            break;
        }
      }
    }
    else {
      std::cerr << "Invalid argument: " << arg << ".\n";
      std::cout << "More info with \"aboutmig -h\".\n";
      return EXIT_INVALID_ARGUMENT;
    }
  }

  if (do_help) {
    helpMsg();
    return 0;
  }
  if (do_version) {
    verMsg();
    return 0;
  }
  if (do_reset) {
    storage::deleteDatafile();
    std::cout << "Deleted datafile.\n";

    return 0;
  }

  if (storage::checkForStorageDir() == false) {
    storage::createStorageDir();
  }
  if (storage::checkForDatafile() == false) {
    storage::createDatafile();
  }

  if (do_add) {
    // Display welcome messsage
    std::string category;
    std::string value;

    category = getCategory();
    std::transform(category.begin(), category.end(), category.begin(), ::toupper);
    value = getValue();

    std::cout << "\nYou entered:\n"
              << ANSI_bold_yellow << "[" << category << "]" << ANSI_reset << ": " << value << "\n";

    storage::saveDatafile(category, value);
    return 0;
  }
  else if (do_list) {
    std::cout << storage::readDatafile();
    return 0;
  }

  std::cerr << "No arguments provided.\n";
  std::cout << "More info with \"aboutmig -h\".\n";
  return EXIT_MISSING_ARGUMENT;
}

// Displaying helper text
void helpMsg()
{
  std::cout << "AboutMig - Store info about yourself!\n\n";
  std::cout << "Usage:	aboutmig -[arguments]\n\n";
  std::cout << "Arguments:\n";
  std::cout << "	-l							List all information.\n";
  std::cout << "	-a							Add information.\n";
  std::cout << "	-r							Reset information\n";
  std::cout << "	-v							Display version.\n";
  std::cout << "	-h							Display this helper text.\n\n";
}

// Displaying version
void verMsg()
{
  std::cout << "AboutMig " << VERSION << "\n\n";
  std::cout
    << "This project uses the 'nlohmann' JSON library, which is licensed under the MIT license.\n";
  std::cout << "More information about the library can be found at:\n";
  std::cout << "https://github.com/nlohmann/json/\n";
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
