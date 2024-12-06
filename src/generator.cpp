#include <iostream>
#include <fstream>
#include <chrono>

#if defined(_WIN32)
    #include "windows.h"
#else 
    #error "Unsupported OS"
#endif

int main() {
    std::ofstream file_out;
    file_out.open("output.txt");
    return 0;
}