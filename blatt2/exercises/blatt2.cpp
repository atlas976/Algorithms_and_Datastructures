#include "../include/blatt2.h"

#include <filesystem>
using namespace std;

#include <vector>
#include <algorithm>

using namespace std;

vector<int> addNumbers(vector<int>& x, vector<int>& y, int base) {
    // Ensure x is the longer vector
    if (x.size() < y.size()) swap(x, y);

    int carry = 0;
    int i = x.size() - 1;
    int j = y.size() - 1;

    // Add from right to left
    while (j >= 0) {
        int sum = x[i] + y[j] + carry;
        x[i] = sum % base;
        carry = sum / base;
        i--;
        j--;
    }

    // Handle remaining carry in x
    while (i >= 0 && carry > 0) {
        int sum = x[i] + carry;
        x[i] = sum % base;
        carry = sum / base;
        i--;
    }

    // Still carry left? Add new digit at front
    if (carry > 0) {
        x.insert(x.begin(), carry);
    }

    return x;
}

/**
 *  ========== Hilfsfunktionen ==========
 *
 *  void printDigits(vector<int>& digits, int base)
 *  -> Gibt die Ziffern des gegebenen vectors aus
 *
 */