#include <iostream>
#include <array>
#include "include/blatt8.h"

void aufgabe3() {
    vector<int> a{5, 4, 9, 10, 2, 8, 7};
    int res = max_subarray(a);
    printf("The maximum subarray has value: %d\n", res);
}

void aufgabe4a() {
    PolynomialParams params{{0, 7}, {1, 2}, {2, -5}, {3, 2}};
    Polynomial p = Polynomial(params);
    p.print();
    p.flip();
    p.print();
} 

void aufgabe4b() {
    PolynomialParams params{{0, 7}, {1, 2}, {2, -5}, {3, 2}};
    Polynomial p = Polynomial(params);
    p.moveUp(0);
    p.print();
}

void aufgabe4c() {
    PolynomialParams params{{0, 7}, {1, 2}, {2, -5}, {3, 2}};
    Polynomial p = Polynomial(params);

    PolynomialParams params2{{0, -1}, {2, 8}, {3, -2}, {4, -1}};
    Polynomial p2 = Polynomial(params2);

    printf("\t");
    p.print();
    printf("+\t");
    p2.print();
    p.add(p2);
    printf("=\t");
    p.print();
}

int main() {
//    aufgabe3();
    aufgabe4a();
    aufgabe4b();
//    aufgabe4c();
}


