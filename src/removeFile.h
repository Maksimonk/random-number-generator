// removeFile.h

#ifndef REMOVEFILE_H
#define REMOVEFILE_H

#include <windows.h>
#include <shellapi.h>
#include <iostream>
#include <fstream>

bool removeFile(const std::string &path); // true = success
void cleanRecycleBin();

#endif // REMOVEFILE_H
