#include "removeFile.h"
#include <cstring>
#include <string>
#include <locale>
#include <shlobj.h>
#include <iostream>

// if exists -> remove -> clean trash bin

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

void deleteFileFromRecycleBin(const std::string& path) {
    SHFILEOPSTRUCTA fileOp = {0};
    char filePathBuffer[MAX_PATH + 1];
    strncpy(filePathBuffer, path.c_str(), MAX_PATH);
    filePathBuffer[path.size() + 1] = '\0';

    fileOp.wFunc = FO_DELETE;
    fileOp.pFrom = filePathBuffer;
    fileOp.fFlags = FOF_ALLOWUNDO | FOF_NOCONFIRMATION | FOF_SILENT;

    int result = SHFileOperationA(&fileOp);
    if (result == 0) {
        std::cout << "File deleted from Recycle Bin successfully." << std::endl;
    } else {
        std::cerr << "Failed to delete the file from Recycle Bin. Error code: " << result << std::endl;
    }
}


