#include <iostream>

#include "include/blatt5.h"


void aufgabe1b() {
    int n = 10;
    float approx = pi(n);
    printf("Pi is approximately: %f\n", approx);
}

void aufgabe3a() {
    int n = 4;
    int k = 2;
    long binom = binom_iter(n, k);
    printf("binom(%d, %d) = %ld\n", n, k, binom);
}

void aufgabe3b() {
    int n = 4;
    int k = 2;
    long binom = binom_rec(n, k);
    printf("binom(%d, %d) = %ld\n", n, k, binom);
}

void aufgabe4a() {
    int x = 4;
    int y = 2;
    int val = g_tailrec(x, y);
    printf("g_tailrec(%d, %d) = %d\n", x, y, val);
}

void aufgabe4b() {
    int x = 4;
    int y = 2;
    int val = g_iter(x, y);
    printf("g_iter(%d, %d) = %d\n", x, y, val);
}


int main() {
    aufgabe1b();
    aufgabe3a();
    aufgabe3b();
    aufgabe4a();
    aufgabe4b();
}
