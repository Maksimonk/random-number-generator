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

int main()
{
    // NEW FILE? /////////////////////////////////////////////
    // std::cout << "Create new file? [y/n] ";
    // char toCreate;
    // std::cin >> toCreate;
    // if (toCreate == 'y')
    // {
    //     createFile(); // 1 MB by default
    // }

    // AMOUNT ////////////////////////////////////////////////
    long long amount;
    std::cout << "Amount of numbers: ";
    std::cin >> amount;

    // NUMBERS GENERATOR /////////////////////////////////////
    std::ofstream numbers;
    numbers.open("numbers.txt");
    std::ofstream bit_numbers;
    bit_numbers.open("bit_numbers.txt");

    if (!numbers.is_open())
    {
        std::cout << "\nAn error occured while opening numbers.txt\n"
                  << std::endl;
        return 1;
    }

    if (!bit_numbers.is_open())
    {
        std::cout << "\nAn error occured while opening bit_numbers.txt\n"
                  << std::endl;
        return 1;
    }
    // NEW NUMBERS APPENDING TO FILE(S)/////////////////////////////
    for (long long i = 0; i < amount; i++)
    {
        createFile(1);             // 64 MB used; 1 MB by default
        double current = moveFile(); // time from testFile moving
        numbers << current << "\n";
        bit_numbers << double_to_binary(current) << "\n";
    }

    numbers.close();
    bit_numbers.close();

    // CHECKING THAT EVERYTHING IS OK ////////////////////////
    numbers.open("numbers.txt");
    bit_numbers.open("bit_numbers.txt");
    if (numbers.is_open() and bit_numbers.is_open())
    {
        std::cout << "\nnumbers.txt and bit_numbers.txt were successfully created\n"
                  << std::endl;
    }
    else
    {
        std::cout << "\nAn error occured while trying to open numbers.txt or bit_numbers.txt for checking\n"
                  << std::endl;
        return 1;
    }

    numbers.close();
    bit_numbers.close();
    return 0;
}
