/* ------------------------------------------------
 * Location: 					src/storage/datafiles.cpp
 * Purpose:						Source file for datafiles
  										related storage code.
 * Autor:							Raphael G. Grubbauer
 * Created:						07.06.2025
 * Copyright:					(c) 2025 Raphael G. Grubbauer
 * License:						MIT
 * ------------------------------------------------
*/
#include <string>

#include "storage/directory.h"

namespace storage {
std::string getDatafile() {
	std::string fileDir = storage::getStorageDir() + "/data.jsonc";
	return fileDir;
}
}
