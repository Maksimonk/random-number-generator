#include "moveFile.h"
#include "removeFile.h"

double moveFile(const std::string &sourcePath)
{
    // DESTINATION = DESKTOP /////////////////////////
    std::string username = getUsername();
    std::string destinationPath = "C:/Users/" + username + "/Desktop/testFile.txt";
    if (fileExists(destinationPath))
    {
        removeFile(destinationPath);
    }
    auto start = std::chrono::high_resolution_clock::now();

    if (std::rename(sourcePath.c_str(), destinationPath.c_str()) != 0)
    {
        std::cerr << "Error moving testFile! Error: " << GetLastError() << std::endl;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    double timeInSeconds = duration.count();
    std::cout << "Time to move testFile: " << timeInSeconds << " seconds" << std::endl;

    if (fileExists(destinationPath))
    {
        removeFile(destinationPath);
    }

    return timeInSeconds;
}

std::string getUsername()
{
    char username[UNLEN + 1];
    DWORD username_len = UNLEN + 1;
    if (GetUserNameA(username, &username_len))
    {
        return std::string(username);
    }
    else
    {
        std::cerr << "Failed to get username. Error: " << GetLastError() << std::endl;
        return "";
    }
}

std::string double_to_binary(double value)
{
    union
    {
        double input;
        uint64_t output;
    } data;

    data.input = value;
    std::bitset<64> bits(data.output);

    return bits.to_string();
}

bool fileExists(const std::string &filePath)
{
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, filePath.c_str(), (int)filePath.size(), NULL, 0);
    std::wstring wFilePath(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, filePath.c_str(), (int)filePath.size(), &wFilePath[0], size_needed);
    DWORD fileAttributes = GetFileAttributesW(wFilePath.c_str());
    return (fileAttributes != INVALID_FILE_ATTRIBUTES && !(fileAttributes & FILE_ATTRIBUTE_DIRECTORY));
}