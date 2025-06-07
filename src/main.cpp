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

#include <storage/directory.h>

void welcomeMsg() {
	std::cout << "===================\n";
	std::cout << "Welcome to AboutMig\n";
	std::cout << "===================\n";
}

// Getting the category
std::string getCategory() {
	std::string category;
	std::cout << "\nEnter category: ";
	std::cin >> category;
	
	return category;
}

// Getting the value of the variable
std::string getValue() {
	std::string value;
	std::cout << "\nEnter value: ";
	std::cin >> value;

	return value;
}

int main() {
	// Display welcome messsage
	std::string category;
	std::string value;
	welcomeMsg();

	category = getCategory();
	value = getValue();

	std::cout << "\n\nYou entered: " << category << " - " << value << "\n";

	std::cout << getStorageDir() << "\n";
}
