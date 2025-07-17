#include "../include/blatt5.h"

/// Aufgabe 1b)
float pi(int n) {
    if (n == 0) return 4;
    return (4 - 8 * (n % 2)) / (2 * n + 1.0) + pi(n - 1);
}

/// Aufgabe 3
long factorial(int n) {
    long f = 1;
    for (int i = 1; i <= n; i += 1)
        f *= i;
    return f;
}

long binom_iter(int n, int k) {
    return factorial(n) / (factorial(k) * factorial(n-k));
}

long binom_rec(int n, int k) {
    if (k == 0 || k == n)
        return 1;
    return binom_rec(n-1, k-1) + binom_rec(n-1, k);
}

/// Aufgabe 4

// Potenzfunktion (man kann diese effizienter implementieren)
int pow(int x, int y) {
    int res = 1;
    for (int i = 0; i < y; i++)
        res *= x;
    return res;
}

// Hilfsfunktion g endrekursiv
// hier benutzen wir die Variable calc, um das Zwischenergebnis zu speichern
int g_tailrec(int x, int y, int calc) {
    if (x < 10)
        return calc + pow(x, y);
    return g_tailrec(x / 10, y+1, calc + pow(x % 10, y));
}

// Funktion g endrekursiv
int g_tailrec(int x, int y) {
    return g_tailrec(x, y, 0);
}

// Funktion g iterativ
int g_iter(int x, int y) {
    int calc = 0;

    while (x >= 10) {
        calc += pow(x % 10, y);
        y += 1;
        x /= 10;
    }
    calc += pow(x, y);

    return calc;
}