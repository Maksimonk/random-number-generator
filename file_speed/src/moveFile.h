// moveFile.h
#ifndef MOVEFILE_H
#define MOVEFILE_H
#include <iostream>
#include <fstream>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <windows.h>
#include <lmcons.h>
#include <string>
#include <bitset>
#include <string>

double moveFile(const std::string &sourcePath = "testFile.txt");
std::string getUsername();
std::string double_to_binary(double value);
bool fileExists(const std::string &filePath);

#endif // MOVEFILE_H