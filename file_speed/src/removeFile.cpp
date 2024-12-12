#include "removeFile.h"
#include <cstring>
#include <string>
#include <locale>
#include <shlobj.h>
#include <iostream>
#include <ShlObj.h>

// if exists -> remove -> clean trash bin (remove deleted file only)

bool removeFile(const std::string &path)
{
    BOOL result = DeleteFileA(path.c_str());

    if (result)
    {
        std::cout << "File deleted." << std::endl;
        return true;
    }
    else
    {
        std::cerr << "Failed to delete the file. Error: " << GetLastError() << std::endl;
        return false;
    }

    cleanRecycleBin();
}

void cleanRecycleBin()
{
    HRESULT result = SHEmptyRecycleBin(NULL, NULL, SHERB_NOCONFIRMATION | SHERB_NOPROGRESSUI | SHERB_NOSOUND);
    if (SUCCEEDED(result))
    {
        std::cout << "Recycle Bin cleaned successfully" << std::endl;
    }
    else
    {
        std::cerr << "An error occured while cleaning Recycle Bin: " << std::hex << result << std::endl;
    }
}
