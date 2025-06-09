/* ------------------------------------------------
 * Location: 					include/storage/datafiles.h
 * Purpose:						Header file for datafiles
  										related storage code.
 * Author:						Raphael G. Grubbauer
 * Created:						07.06.2025
 * Copyright:					(c) 2025 Raphael G. Grubbauer
 * License:						MIT
 * ------------------------------------------------
*/

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
}

#endif
