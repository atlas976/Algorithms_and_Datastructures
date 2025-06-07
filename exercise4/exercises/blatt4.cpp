#include "../include/blatt4.h"


/*
vector<int> plusOne(vector<int>& digits) {
    vector<int> sol(digits); // copie of digits
    int carry = 0; // carry bit
    int solLength = sol.size();

    //increment the last vector element & calculate the first carry
    sol[solLength - 1] = sol[solLength - 1] + 1;
    if (sol[solLength - 1] > 9) {carry = 1; sol[solLength - 1] = 0;}

    //increment the single elements as long as there is a carry
    for (int i = solLength - 2; i >= 0; i--) {
        sol[i] = sol[i] + carry;
        if (sol[i] > 9) {carry = 1; sol[i] = 0;}
        else {carry = 0; break;}
    }

    //if there is still a last carry
    //--> set first element to 1 and create a new vector element with 0 at the end
    if (carry) {sol[0] = 1; sol.push_back(0);}
    return sol;
}
*/

//same plusOne function as before, but now with iterators
vector<int> plusOne(vector<int>& digits) {
    vector<int> sol(digits); //copie of digits
    int carry = 0;
    vector<int>::reverse_iterator solRBegin = sol.rbegin();

    //increment last vector element and calculate the first carry
    *solRBegin = *solRBegin + 1;
    if (*solRBegin > 9) {carry = 1; *solRBegin = 0;}

    //increment through the singel digits by using an iterator
    for (auto it = (++solRBegin); it != sol.rend(); ++it) {
        *it = *it + carry;
        if (*it > 9) {carry = 1;*it = 0;}
        else {carry = 0; break;}
    }

    //last carry bit --> first vector element = 1 & isert 0 at the end
    if (carry) {*(--sol.rend()) = 1, sol.push_back(0);}
    return sol;
}


/*
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
*/

vector<int> addNumbers(vector<int>& x, vector<int>& y, const int base) {
    //be sure x is bigger, as it makes things way more simple
    if (x.size() < y.size()) swap(x, y);

    //var
    int carry = 0;
    int sum = 0;
    vector<int>::reverse_iterator xRIterator = x.rbegin();
    vector<int>::reverse_iterator yRIterator = y.rbegin();

    //add from right to left
    while (yRIterator != y.rend()) {
        sum = *yRIterator + *xRIterator + carry;
        *xRIterator = sum % base;
        carry = sum / base;
        yRIterator++;
        xRIterator++;
    }

    // Handle remaining carry in x
    while (xRIterator != x.rend() && carry > 0) {
        sum = *xRIterator + carry;
        *xRIterator = sum % base;
        carry = sum / base;
        xRIterator++;
    }

    //handle the remaining carry in x
    if (carry > 0) {x.insert(x.begin(), carry);}

    return x;
}



/**
 *  ========== Helper Functions ==========
 *
 *  void printDigits(vector<int>& digits, int base)
 *  -> Prints the digits from the given vector as a decimal number
 *
 *  void printList(vector<int>& numbers)
 *  -> Prints the list
 *
 */



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