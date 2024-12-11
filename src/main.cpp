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

    // CREATING FILES, CHECKING /////////////////////////////////////
    std::ofstream numbers;
    numbers.open("numbers.txt");
    std::ofstream bit_numbers;
    bit_numbers.open("bit_numbers.txt");
    std::ofstream final_random;
    final_random.open("final_random.txt");
    std::ofstream bit_final_random;
    bit_final_random.open("bit_final_random.txt");

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

    if (!final_random.is_open())
    {
        std::cout << "\nAn error occured while opening final_random.txt\n"
                  << std::endl;
        return 1;
    }

    if (!bit_final_random.is_open())
    {
        std::cout << "\nAn error occured while opening bit_final_random.txt\n"
                  << std::endl;
        return 1;
    }

    // NEW NUMBERS APPENDING TO FILE(S)/////////////////////////////
    for (long long i = 0; i < amount; i++)
    {
        createFile();                // 1 MB by default
        double current = moveFile(); // time from testFile moving
        numbers << current << "\n";
        bit_numbers << double_to_binary(current) << "\n";

        long long result = current * 1000000000 + 1;
        auto result1 = 10000000000000% result;
        final_random << current << "\n";
        bit_final_random << double_to_binary(result1) << "\n";
    }

    numbers.close();
    bit_numbers.close();
    final_random.close();
    bit_final_random.close();

    // CHECKING THAT EVERYTHING IS OK ////////////////////////
    std::ifstream check_numbers("numbers.txt");
    std::ifstream check_bit_numbers("bit_numbers.txt");
    std::ofstream check_final_random("final_random.txt");
    std::ofstream check_bit_final_random("bit_final_random.txt");

    if (check_numbers.is_open() && check_bit_numbers.is_open() && check_final_random.is_open() && check_bit_final_random.is_open())
    {
        std::cout << "\nall files were successfully created\n"
                  << std::endl;
    }
    else
    {
        std::cout << "\nAn error occured while trying to open files for checking\n"
                  << std::endl;
        return 1;
    }

    check_numbers.close();
    check_bit_numbers.close();
    check_final_random.close();
    check_bit_final_random.close();
    return 0;
}
