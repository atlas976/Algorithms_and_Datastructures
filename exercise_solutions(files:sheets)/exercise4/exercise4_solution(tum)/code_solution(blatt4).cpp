#include "../include/blatt4.h"

vector<int> plusOne(vector<int>& digits) {
    if(digits.empty())
        return digits;

    vector<int> sol(digits); // Kopie von digits anlegen
    // in der Angabe ist nicht genau spezifiziert, ob wir digits verändern dürfen

    auto it = sol.rbegin();     // Reverse Iterator initialisieren
    while(*it == 9) { // Wichtig: vorher sicherstellen, dass sol nicht leer ist, sonst ist it invalid
        *it = 0;    // Digit auf 0 setzen
        ++it;       // Eine Stelle weiter
        if(it == sol.rend()) {      // Ende der reverse-iteration bei rend (past-the-end value)
            sol.insert(sol.begin(), 1);     // Element am Anfang einfügen
            // Achtung: Operationen, die den vector verändern, invalidieren die iteratoren!
            // -> it ab jetzt nicht mehr verwenden!!
            return sol;
        }
    }
    (*it)++; // Klammern sind hier wichtig: ++ hat höhere Bindung als *. *it++ liest Wert an Stelle it
    return sol;
}


vector<int> addNumbers(vector<int>& x, vector<int>& y, int base) {
    // make sure y is the number with more digits
    if(x.size() > y.size()) {
        vector<int> tmp = x;
        x = y;
        y = tmp;
    }

    int carry = 0;
    auto itX = x.rbegin();
    // traverse digits of y using reverse iterator
    for(auto itY = y.rbegin(); itY != y.rend(); ++itY) {
        // if x still has digits, add its current digit to carry and increment iterator
        if(itX != x.rend()) {
            carry += *itX;
            ++itX;
        } else if (carry == 0) break; // smaller number is over and there is no carry -> addition is done

        // add carry to y and set carry to 0
        *itY += carry;
        carry = 0;

        // if overflow at current digit: reset digit and add to carry
        if(*itY >= base) {
            *itY -= base;
            carry = 1;
        }
    }

    // if y ran out of digits, but we still have a carry: add it to front
    if(carry > 0) {
        y.insert(y.begin(), carry);
    }

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
