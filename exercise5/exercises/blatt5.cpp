#include "../include/blatt5.h"


//exercise 1b
float pi(int n) {
    float piSum = 0;


    //check if f(n = 0)
    if (n == 0) {return 4;}

    //check if n is even
    if (n%2 == 0) {
        piSum = (4.0)/(2.0*float(n) + 1) + pi(n - 1);
    }
    //check if n is odd
    else if (n%2 != 0) {
        piSum = -4/(2*float(n) + 1) + pi(n - 1);
    }


    //return
    return piSum;
}


//exercise 3
long binom_iter(int n, int k) {
    //var dec
    int nFac = 1; int kFac = 1; int nMinuskFac = 1;

    //n-th factorial, k-th factorial, (n-k)-th factorial calculating
    for (int i = 1; i <= n; i++) {nFac = nFac * i;}
    for (int i = 1; i <= k; i++) {kFac = kFac * i;}
    for (int i = 1; i <= (n-k); i++) {nMinuskFac = nMinuskFac * i;}

    //calculate binominal and return
    return nFac/(kFac * nMinuskFac);
}

long binom_rec(int n, int k) {

    //exeption case n=k
    if (k == n) {return 1;}
    if (k == 0) {return 1;}

    //calc next rec
    return binom_rec(n - 1, k - 1) + binom_rec(n - 1, k);
}

//exercise 4

// helperfunction g endrecursiv
int g_tailrec_help(int x, int y) {
    //var dec
    int power = 1;

    //calc power
    for (int i = 1; i <= y; i++) {power = power * x;}

    //return
    return power;
}


// Function g endrecursiv
int g_tailrec(int x, int y) {
    if (x < 10) {return g_tailrec_help(x, y);}
    if (x >= 10) {return g_tailrec_help(x%10, y) + g_tailrec(x/10, y + 1);}
}

// Function g iterativ
int g_iter(int x, int y) {
    //var dec
    int sol = 0;
    int newX = x;

    //iterate until newX < 10
    while (newX >= 10) {
        sol = sol + g_tailrec_help(newX%10, y);
        newX = newX / 10;
        y += 1;
    }

    //add x^y to sol
    return sol + g_tailrec_help(newX, y);
}
