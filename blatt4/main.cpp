#include <iostream>

#include "include/blatt4.h"

void aufgabe1() {
    vector<int> digits = {3,4,7,6,9};

    printf("Before increment: ");
    printDigits(digits);

    vector<int> incremented = plusOne(digits);

    printf("After increment: ");
    printDigits(incremented);
}

void aufgabe2() {
    vector<int> digitsA = {42, 53, 28};
    vector<int> digitsB = {37};
    int base = 55;

    printf("Before adding:\n");
    printDigits(digitsA);
    printDigits(digitsB);

    vector<int> added = addNumbers(digitsA, digitsB, base);

    printf("After adding: ");
    printDigits(added);
}


int main() {
    aufgabe1();
//    aufgabe2();
}
