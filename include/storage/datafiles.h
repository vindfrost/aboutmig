/*==============================================================================
 * File:        datafiles.h
 * Path:        include/storage/
 * Purpose:     Header file for datafile-related storage code
 * 
 * Author:      Raphael G. Grubbauer
 * Created:     2025-06-07
 * License:     MIT License
 * Copyright:   (c) 2025 Raphael G. Grubbauer
 *============================================================================*/

#ifndef __STORAGE_DATAFILES_H
#define __STORAGE_DATAFILES_H

#include <string>

namespace storage {
// Getting the path of the datafile
std::string getDatafile();
// Checking if datafile exists
bool checkForDatafile();
// Creating datafile
void createDatafile();
// Saving data to the datafile
void saveDatafile(std::string catagory, std::string value);
// Reading data from the datafile
std::string readDatafile();
// Deleting datafile
void deleteDatafile();
}

#endif
