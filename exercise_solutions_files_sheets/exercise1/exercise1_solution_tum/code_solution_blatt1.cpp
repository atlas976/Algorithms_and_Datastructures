#include "../include/blatt1.h"

/**
 * Aufgabe 1c, i)
 */
bool returnTrue() {
    return true;
}

/**
 * Aufgabe 1c, ii)
 */
int returnPositiveOdd() {
    return 2537;
}

/**
 * Aufgabe 1c, iii)
 */
int returnPrime() {
    return 37;
}



/**
 * Aufgabe 2a)
 */
void reverse(vector<int>& numbers) {
    int l = 0, r = numbers.size() - 1;
    while(l < r) {
        int tmp = numbers[l];
        numbers[l] = numbers[r];
        numbers[r] = tmp;
        l++;
        r--;
    }
}

/**
 * Aufgabe 2b)
 */
vector<int> plusOne(vector<int>& digits) {
    vector<int> res(digits.size());

    bool success = false;
    for(int i = digits.size() - 1; i >= 0; i--) {
        if(success) {
            res[i] = digits[i];
        } else {
            if(digits[i] == 9) {
                res.at(i) = 0;
            } else {
                res.at(i) = digits.at(i) + 1;
                success = true;
            }
        }
    }
    if(!success) {
        vector<int> resExt;
        resExt.push_back(1);
        for(int i: res)
            resExt.push_back(i);
        return resExt;
    }
    return res;
}

/**
 * Aufgabe 2c)
 */
vector<int> findPeaks(vector<int>& mountain) {
    vector<int> peaks;
    if(mountain.size() >= 2) {
        for(int i = 1; i < mountain.size() - 1; i++) {
            if(mountain[i] > mountain[i-1] && mountain[i] > mountain[i+1]) {
                peaks.push_back(i);
            }
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

