#include <iostream>

#include "include/blatt7.h"
#include <gtest/gtest.h>

void aufgabe2() {
    auto [order, survivor] = josephus(7, 3);
    printList(order);
    printf("Survivor: %d\n", survivor);
}

void aufgabe3() {
    PolynomialParams params{{0, 7}, {1, 2}, {2, -5}, {3, 2}};
    Polynomial p = Polynomial(params);
    p.print();
    printf("%f\n", p.evaluate(4.23f));


    PolynomialParams params2{{0, -1}, {2, 8}, {3, -2}, {4, -1}};
    Polynomial p2 = Polynomial(params2);
    p2.print();
    bool equal = p.equalTo(p2);
    printf("The two polynomials are %sequal!", equal ? "" : "NOT ");
}

int main() {
    aufgabe2();
//    aufgabe3();
}
