#include <iostream>
#include "include/blatt3.h"

void aufgabe1() {
    vector<int> a{5, 4, 9, 10, 2, 8, 7};
    int res = max_subarray(a);
    printf("The maximum subarray has value: %d\n", res);
}

void aufgabe2() {
    int n = 10;
    vector<int> order = examRoomOrder(n);
    printList(order);
}

int main() {
//    aufgabe1();
    aufgabe2();
}
