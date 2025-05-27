#include "../include/blatt1.h"


bool returnTrue(){
    return true;
}


int returnPositiveOdd() {
    return 7;
}


int returnPrime() {
    return 13;
}



/**
 * Aufgabe 2a)
 */
void reverse(vector<int>& numbers) {
    int buff = 0;
    for (int i = 0; i < numbers.size()/2; i++) { //number = [anderer vektor] lässt einen vektor "in" den anderen kopieren
        buff = numbers[i];
        numbers[i] = numbers[numbers.size()-1-i];
        numbers[numbers.size()-1-i] = buff;
    }
}

/**
 * Aufgabe 2b)
 */
vector<int> plusOne(vector<int>& digits) {
    vector<int> sol;
    int digits_Length = digits.size();
    sol = digits;
    sol[digits_Length-1] += 1; // inkrementieren des letzten vektor eintrags
    for (int i = digits_Length-1; i >= 0; i--) { // test ob die ziffer größer 10 ist und anpassen des vektors
        if (sol[i] == 10) {
            sol[i] = 0;
            if (i != 0) sol[i - 1] += 1;
        }
        else break; // falls fertig kann schleife beendet werden
        if (i == 0 ) {
            sol[i] = 1; // falls sich eine neue 10ner stelle ergibt
            sol.push_back(0);
        }
    }
    return sol;
}

/**
 * Aufgabe 2c)
 */

//kann man besser optimieren (bsp.: +2 wenn peak gefunden --> Konstante in O(n) verkleinern
vector<int> findPeaks(vector<int>& mountain) {
    std::vector<int> peaks;
    int i = 0;  //variable definieren, die die größe des vektors beinhaltete --> dadurch weniger funktions aufrufe
    if (mountain.size() == 0) return peaks;
    for (i = 1; i < mountain.size() - 1; i++) {
        if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {
            peaks.push_back(i);
        }
    }
    return peaks;
}


/**
 *  ========== Hilfsfunktionen ==========
 *
 *  void printDigits(vector<int>& digits)
 *  -> Gibt die Ziffern des gegebenen vectors als Dezimalzahl aus
 *
 *  void printList(vector<int>& numbers)
 *  -> Gibt die Liste aus
 *
 */

