#include "../include/blatt2.h"

vector<int> addNumbers(vector<int>& x, vector<int>& y, int base) {
    // make sure y is the number with more digits
    if(x.size() > y.size()) {
        // TODO: swap x and y
        vector<int> tmp = x;
        x = y;
        y = tmp;
    }

    // numbers now look roughly like this
    // y:   y0 y1 y2 y3 y4 y5
    // x:         x0 x1 x2 x3

    // save possible digit overflow in a carry variable
    int carry = 0;

    // traverse digits of y: index i counts from the back for both x and y
    for(int i = 0; i < y.size(); i++) {
        int value = 0; // accumulates value of current digit

        // account for carry in value
        value += carry;

        // if x still has digits, add its current digit to value
        if(i < x.size()) {
            value += x.at(x.size() - i - 1);
        }

        // add value to y
        y.at(y.size() - i - 1) += value;

        // adjust carry. If overflow at current digit: reset digit and add rest to carry
        if(y.at(y.size() - i - 1) >= base) {
            y.at(y.size() - i - 1) -= base;
            carry = 1;
        } else {
            carry = 0;
        }
    }

    // if y ran out of digits, but we still have a carry: add 1 front
    if(carry > 0) {
        // insert 1 at back
        y.push_back(1);
        // then swap until the front of the vector
        for(int i = y.size() - 1; i > 0; i--) {
            int tmp = y.at(i-1);
            y.at(i-1) = y.at(i);
            y.at(i) = tmp;
        }
    }

    return y;
}

/**
 *  ========== Hilfsfunktionen ==========
 *
 *  void printDigits(vector<int>& digits, int base)
 *  -> Gibt die Ziffern des gegebenen vectors aus
 *
 */