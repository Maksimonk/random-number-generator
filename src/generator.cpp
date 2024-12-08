#include <iostream>
#include <fstream>
#include <chrono>
#include "testFileCreator.h"

#if defined(_WIN32)
    #include "windows.h"
#else 
    #error "Unsupported OS"
#endif

int counter = 0;

int generator(){
    return counter++;
}

int main() {
    std::cout << "Create new file? [y/n] ";
    char toCreate;
    std::cin >> toCreate;
    if (toCreate == 'y') {
    createFile(); // 512 MB by default
    }

    long long amount;
    std::cout << "amount of numbers: ";
    std::cin >> amount;

    std::ofstream file_out;
    file_out.open("numbers.txt");
    if (!file_out.is_open()){
        std::cout << "An error occured while opening numbers.txt" << std::endl;
        return 1;
    }
    
    for (long long i = 0; i < amount; i++){
        file_out<< generator() << "\n"; // it is ok
    }
    file_out.close();
    return 0;
}
