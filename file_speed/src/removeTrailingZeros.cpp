#include "removeTrailingZeros.h"

std::string removeTrailingZeros(const std::string& input, int FirstBitToBeDeletedExceptSignBit) {
    const char fisrtSignBit = input[0];
    std::string modifiedInput = fisrtSignBit + input.substr(FirstBitToBeDeletedExceptSignBit);
    size_t pos = modifiedInput.find_last_not_of('0');
    if (pos == std::string::npos) {
        return "0";
    }
    return modifiedInput.substr(0, pos + 1);
}
