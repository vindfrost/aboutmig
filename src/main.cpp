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

#include "storage/directory.h"
#include "storage/datafiles.h"

// Display welcome message
void welcomeMsg() {
	std::cout << "===================\n";
	std::cout << "Welcome to AboutMig\n";
	std::cout << "===================\n\n";
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

int main() {
	// Display welcome messsage
	std::string category;
	std::string value;
	welcomeMsg();

	category = getCategory();
	value = getValue();

	std::cout << "\nYou entered: \033[33m" << category << "\033[0m: " << value << "\n\n\n\n";

	if (storage::checkForStorageDir() == false) {
		storage::createStorageDir();
	}
	if (storage::checkForDatafile() == false) {
		storage::createDatafile();
	}
	storage::saveDatafile(category, value);

	std::cout << storage::readDatafile();
}
