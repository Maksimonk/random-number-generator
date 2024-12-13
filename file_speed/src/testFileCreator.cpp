#include <fstream>
#include <iostream>
#include <random> //only used for filling testFile
#include "testFileCreator.h"
#include <windows.h>

void createFile(long long size)
{
    // size = 1024LL * 1024LL * size;
    size = 1024LL * size; // kb
    std::ofstream testFile("testFile.txt", std::ios::binary);
    
    if (!testFile) {
        std::cerr << "Error of openning file for writing. Create new file failed. Error: " << GetLastError() << std::endl;
        return;    
    }

    const size_t bufferSize = 1024 * 1024;
    char* buffer = new char[bufferSize];

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 4095);

    for (auto i = 0; i < bufferSize; ++i){
        buffer[i] = static_cast<char>(dis(gen));
    }

    long long bytesWritten = 0;
    while (bytesWritten < size) {
        testFile.write(buffer, bufferSize);
        bytesWritten += bufferSize;
    }

    testFile.close();
    delete[] buffer;

    std::cout << "testFile created successfully" << std::endl;
}