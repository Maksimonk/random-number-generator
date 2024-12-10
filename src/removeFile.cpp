#include "removeFile.h"
#include <cstring>
#include <string>
#include <locale>
#include <shlobj.h>
#include <iostream>
#include <ShlObj.h>

// if exists -> remove -> clean trash bin (remove deleted file only)

bool removeFile(const std::string& path) {
    BOOL result = DeleteFileA(path.c_str());

    if (result) {
        std::cout << "File deleted." << std::endl;
        return true;
    } else {
        std::cerr << "Failed to delete the file. Error: " << GetLastError() << std::endl;
        return false;
    }

    deleteFileFromRecycleBin(path);
}


void deleteFileFromRecycleBin(const std::string& filepath) {
    std::wstring path = stringToWstring(filepath);
    if (DeleteFileW(path.c_str())) {
    } else {
        std::cerr << "Failed to delete file from recycle bin: " << GetLastError() << std::endl;
    }
}

std::wstring stringToWstring(const std::string& str){
    std::wstring wstr(str.begin(), str.end());
    return wstr;
}