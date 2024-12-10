#include <iostream>
#include <fstream>
#include <chrono>
#include "testFileCreator.h"
#include "moveFile.h"
#include "removeFile.h"

#if defined(_WIN32)
#else 
    #error "Unsupported OS"
#endif

// TODO: remove
int counter = 0;
int generator(){
    return counter++;
}

int main() {
    // NEW FILE? /////////////////////////////////////////////
    std::cout << "Create new file? [y/n] ";
    char toCreate;
    std::cin >> toCreate;
    if (toCreate == 'y') {
    createFile(); // 5 GB; 512 MB by default
    }

    // AMOUNT ////////////////////////////////////////////////
    long long amount;
    std::cout << "amount of numbers: ";
    std::cin >> amount;

    // NUMBERS GENERATOR /////////////////////////////////////
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

    // START COPYING
    moveFile();
    removeFile();

    return 0;
}
