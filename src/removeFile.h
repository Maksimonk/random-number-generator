// removeFile.h

#ifndef REMOVEFILE_H
#define REMOVEFILE_H

#include <windows.h>
#include <shellapi.h>
#include <iostream>
#include <fstream>


bool removeFile(const std::string& path = "C:/Users/ddyam/Desktop/testFile.txt"); // true = success
void deleteFileFromRecycleBin(const std::string& path = "C:/Users/ddyam/Desktop/testFile.txt");
std::wstring stringToWstring(const std::string& str);

#endif // REMOVEFILE_H
