#include <iostream>
#include <fstream>
#include <chrono>
#include "testFileCreator.h"
#include "moveFile.h"

#if defined(_WIN32)
    #include "windows.h"
    #include <shellapi.h>
#else 
    #error "Unsupported OS"
#endif

// TODO: remove
int counter = 0;
int generator(){
    return counter++;
}

int main() {
    std::cout << "Create new file? [y/n] ";
    char toCreate;
    std::cin >> toCreate;
    if (toCreate == 'y') {
    createFile(); // 5 GB; 512 MB by default
    }

    long long amount;
    std::cout << "amount of numbers: ";
    std::cin >> amount;

    std::ofstream numbers;
    numbers.open("numbers.txt");
    if (!numbers.is_open()){
        std::cout << "An error occured while opening numbers.txt" << std::endl;
        return 1;
    }
    
    for (long long i = 0; i < amount; i++){
        numbers<< generator() << "\n"; // it is ok
    }
    numbers.close();

    // SHEmptyRecycleBin(NULL, NULL, SHERB_NOCONFIRMATION | SHERB_NOPROGRESSUI | SHERB_NOSOUND);

    // START COPYING
    moveFile();





    return 0;
}
