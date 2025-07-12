#include <iostream>

#include "include/blatt6.h"

void aufgabe2() {
    int n = 4;
    int k = 2;
    long binom = binom_memo(n, k);
    printf("binom(%d, %d) = %ld\n", n, k, binom);
}

void aufgabe3() {
    vector<int> digits = {3, 6, 10, 25, 8, 1, 33, 2};

    printf("Before sort: ");
    printList(digits);

    selection_sort(digits);

    printf("After sort: ");
    printList(digits);
}

void aufgabe4a() {
    vector<int> list = {23,25,36,1,4,8,12,15,18};

    printf("List: ");
    printList(list);

    int index = search(list, 3, 8);

    printf("Index of 8 is %d\n", index);
}

void aufgabe4b() {
    vector<int> list = {23,25,36,1,4,8,12,15,18};

    printf("List: ");
    printList(list);

    int shift = get_shift(list);

    printf("Shift is %d\n", shift);
}

int main() {
    aufgabe2();
    aufgabe3();
    aufgabe4a();
    aufgabe4b();
}
