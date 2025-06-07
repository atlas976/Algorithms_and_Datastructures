#include <iostream>

#include "include/blatt2.h"
void aufgabe1() {
    vector<int> digitsA = {42, 53, 28};
    vector<int> digitsB = {37};
    int base = 55;

    printf("Before adding:\n");
    printDigits(digitsA, base);
    printDigits(digitsB, base);

    vector<int> added = addNumbers(digitsA, digitsB, base);

    printf("After adding: ");
    printDigits(added, base);
}


int main() {
    aufgabe1();
}
