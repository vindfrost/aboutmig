/* ------------------------------------------------
 * Location: 					src/main.cpp
 * Purpose:						Main source file
 * Autor:							Raphael G. Grubbauer
 * Created:						03.06.2025
 * Copyright:					(c) 2025 Raphael G. Grubbauer
 * License:						MIT
 * ------------------------------------------------
*/

#include <iostream>
#include <string>
#include <algorithm>

#include "storage/directory.h"
#include "storage/datafiles.h"

void helpMsg() {
	std::cout << "AboutMig - Store info about yourself!\n\n";
	std::cout << "Usage:	aboutmig -[arguments]\n\n";
	std::cout << "Arguments:\n";
	std::cout << "	-h							Display this helper text.\n";
	std::cout << "	-l							List all information.\n";
	std::cout << "	-a							Add information.\n\n";
}

// Getting the category (allow spaces)
std::string getCategory() {
    std::string category;
    std::cout << "Enter category: ";
    std::getline(std::cin, category);
    return category;
}

// Getting the value (allow spaces)
std::string getValue() {
    std::string value;
    std::cout << "Enter value: ";
    std::getline(std::cin, value);
    return value;
}

int main(int argc, char* argv[]) {
	// Argument values
	bool do_list = false;
	bool do_add = false;
	bool do_help = false;

	for (int i = 1; i < argc; ++i) {
        const char* arg = argv[i];

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
										case 'h':
												do_help = true;
												break;
                    default:
                        std::cerr << "Unknown option: -" << arg[j] << ".\n";
												std::cout << "More info with \"aboutmig -h\".\n";
												exit(4);
                        break;
                }
            }
        } else {
            std::cerr << "Invalid argument: " << arg << ".\n";
						std::cout << "More info with \"aboutmig -h\".\n";
						exit(4);
        }
    }

	if (do_help) {
		helpMsg();
		exit(0);
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
		category = category;
		std::transform(category.begin(), category.end(), category.begin(), ::toupper);	
		value = getValue();

		std::cout << "\nYou entered:\n\033[33m" << category << "\033[0m: " << value << "\n\n\n\n";

		storage::saveDatafile(category, value);
		exit(0);
	} else if (do_list) {
		std::cout << storage::readDatafile();
		exit(0);
	}

	// If no valid args given
	if (!do_list && !do_add) {
    std::cerr << "No arguments provided.\n";
		std::cout << "More info with \"aboutmig -h\".\n";

    exit(3);
  }
}
