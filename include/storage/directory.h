/*==============================================================================
 * File:        directory.h
 * Path:        include/storage/
 * Purpose:     Header file for folder-related storage code
 * 
 * Author:      Raphael G. Grubbauer
 * Created:     2025-06-07
 * License:     MIT
 * Copyright:   (c) 2025 Raphael G. Grubbauer
 *============================================================================*/

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
