//
// Created by Robin on 25.03.24.
//

#include <vector>
#include <sstream>
#include <stdexcept>
#include <string>

#ifndef PROGRAMMIERAUFGABEN_BLATT0_H
#define PROGRAMMIERAUFGABEN_BLATT0_H

using std::vector;

bool returnTrue();

int returnPositiveOdd();

int returnPrime();

vector<int> plusOne(vector<int>& digits);

void reverse(vector<int>& numbers);

vector<int> findPeaks(vector<int>& mountain);

static void printDigits(const std::vector<int>& digits) {
    std::stringstream ss;
    for (size_t i = 0; i < digits.size(); ++i) {
        int digit = digits[i];
        if (digit < 0) {
            throw std::invalid_argument("Digit at index " + std::to_string(i) + " is negative: " + std::to_string(digit));
        }
        if (digit >= 10) {
            throw std::invalid_argument("Digit at index " + std::to_string(i) + " is too large (>= 10): " + std::to_string(digit));
        }
        ss << digit;
    }
    printf("%s\n", ss.str().c_str());
}

static void printList(vector<int>& numbers) {
    std::stringstream ss;
    std::string sep;
    for (int i: numbers) {
        ss << sep << i;
        sep = ", ";
    }
    printf("%s\n", ss.str().c_str());
}

#endif //PROGRAMMIERAUFGABEN_BLATT0_H
