#include "../include/blatt2.h"

vector<int> addNumbers(vector<int>& x, vector<int>& y, int base) {
    // make sure y is the number with more digits
    if(x.size() > y.size()) {
        // TODO: swap x and y
    }

    // numbers now look roughly like this
    // y:   y0 y1 y2 y3 y4 y5
    // x:         x0 x1 x2 x3

    // save possible digit overflow in a carry variable
    int carry = 0;

    // traverse digits of y: index counts from the back for both x and y
    for(/* TODO: iterate over digits of y */) {
        int value = 0; // accumulates value of current digit

        // TODO: account for carry

        // TODO: if x still has digits, add its current digit to value (make sure indices match properly between x and y)

        // TODO: add value to y

        // TODO: adjust carry. If overflow at current digit of y: reset digit and add remainder to carry
    }

    // TODO: if y ran out of digits, but we still have a carry: insert 1 at the front

    return y;
}