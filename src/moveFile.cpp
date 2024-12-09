#include "moveFile.h"
#include "removeFile.h"

// TODO: chrono type and return the result after moving?
void moveFile(const std::string& sourcePath, const std::string& destinationPath) {
    removeFile(destinationPath);
    auto start = std::chrono::high_resolution_clock::now();

    if (std::rename(sourcePath.c_str(), destinationPath.c_str()) != 0) {
        std::cerr << "Error moving file!" << std::endl;
        return;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;

    std::cout << "Time to move file: " << duration.count() << " seconds" << std::endl;
}

