/* ------------------------------------------------
 * Location: 					src/storage/directory.h
 * Purpose:						Header file for folder
  										related storage code.
 * Author:						Raphael G. Grubbauer
 * Created:						07.06.2025
 * Copyright:					(c) 2025 Raphael G. Grubbauer
 * License:						MIT
 * ------------------------------------------------
*/

#ifndef __STORAGE_DIRECTORY_H
#define __STORAGE_DIRECTORY_H 

#include <string>

namespace storage {
// Getting the location for the data directory
std::string getStorageDir();
// Checking if the data directory exists
bool checkForStorageDir();
// Creating the data directory
void createStorageDir();
}

#endif
