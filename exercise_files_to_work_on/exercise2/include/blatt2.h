//
// Created by Robin on 25.03.24.
//
#include <sstream>
#include <vector>

#ifndef PROGRAMMIERAUFGABEN_BLATT2_H
#define PROGRAMMIERAUFGABEN_BLATT2_H

using std::vector;

vector<int> addNumbers(vector<int>& x, vector<int>& y, int base);

static void printDigits(vector<int>& digits, int base) {
    std::stringstream ss;
    std::string sep;
    for (size_t i = 0; i < digits.size(); ++i) {
        int digit = digits[i];
        if (digit < 0) {
            throw std::invalid_argument("Digit at index " + std::to_string(i) + " is negative: " + std::to_string(digit));
        }
        if (digit >= base) {
            throw std::invalid_argument("Digit at index " + std::to_string(i) + " is too large (>= base): " + std::to_string(digit));
        }
        ss << sep << digit;
        sep = ":";
    }
    printf("%s\n", ss.str().c_str());
}

#endif //PROGRAMMIERAUFGABEN_BLATT2_H
