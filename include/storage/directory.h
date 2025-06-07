/* ------------------------------------------------
 * Location: 					src/storage/directory.h
 * Purpose:						Header file for folder
  										related storage code.
 * Autor:							Raphael G. Grubbauer
 * Created:						07.06.2025
 * Copyright:					(c) 2025 Raphael G. Grubbauer
 * License:						MIT
 * ------------------------------------------------
*/

#ifndef __STORAGE_DIRECTORY_H
#define __STORAGE_DIRECTORY_H 

#include <string>

std::string getStorageDir();
bool checkForStorageDir();
void createStorageDir();

#endif
