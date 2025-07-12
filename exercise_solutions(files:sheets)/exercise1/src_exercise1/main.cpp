#include <iostream>
#include "include/blatt1.h"

using namespace std;

void aufgabe1() {
    vector<int> numbers = {12, 23, 34, 45, 56, 67, 78};

    printf("Original List:\t");
    printList(numbers);

    reverse(numbers);

    printf("Reversed:\t\t");
    printList(numbers);
}

void aufgabe2() {
    vector<int> digits = {3,4,7,6,9};

    printf("Before increment: ");
    printDigits(digits);

    vector<int> incremented = plusOne(digits);

    printf("After increment: ");
    printDigits(incremented);
}

void aufgabe3() {
    vector<int> mountain = {1,4,3,8,5};
    printf("Mountain:\t");
    printList(mountain);

    vector<int> peaks = findPeaks(mountain);

    printf("Peaks:\t");
    printList(peaks);
}


int main() {
    aufgabe1();
    aufgabe2();
    aufgabe3();
    return 0;
}
