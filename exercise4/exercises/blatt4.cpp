#include "../include/blatt4.h"

vector<int> plusOne(vector<int>& digits) {
    vector<int> sol(digits); // Kopie von digits anlegen
    int carry = 0; // carry bit anlegen
    int solLength = sol.size();

    //inkrementieren des letzten vektor elements, und erster übertrag berechnen
    sol[solLength - 1] = sol[solLength - 1] + 1;
    if (sol[solLength - 1] > 9) {carry = 1; sol[solLength - 1] = 0;}

    //inkrementieren mittels des carrys solange es einen übertrag gibt
    for (int i = solLength - 2; i >= 0; i--) {
        sol[i] = sol[i] + carry;
        if (sol[i] > 9) {carry = 1; sol[i] = 0;}
        else {carry = 0; break;}
    }

    //letztes carry bit, erhöhen der vektor zehnerstelle
    if (carry) {sol[0] = 1; sol.push_back(0);}
    return sol;
}


vector<int> addNumbers(vector<int>& x, vector<int>& y, int base) {
    // TODO
    return y;
}

/**
 *  ========== Hilfsfunktionen ==========
 *
 *  void printDigits(vector<int>& digits, int base)
 *  -> Gibt die Ziffern des gegebenen vectors als Dezimalzahl aus
 *  -> Wirft eine Exception, falls ein digit invalid ist (negativ oder >= base)
 *
 *  void printList(vector<int>& numbers)
 *  -> Gibt die Liste aus
 *
 */