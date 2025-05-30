#include "../include/blatt1.h"



//warmup
bool returnTrue(){
    return true;
}

int returnPositiveOdd() {
    return 7;
}

int returnPrime() {
    return 13;
}



//exercise 2a)
void reverse(vector<int>& numbers) {
    int buff = 0; //buffer var

    for (int i = 0; i < numbers.size()/2; i++) {
        buff = numbers[i];
        numbers[i] = numbers[numbers.size()-1-i];
        numbers[numbers.size()-1-i] = buff;
    }
}



//exercise 2b)
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



//exercise 2c)
vector<int> findPeaks(vector<int>& mountain) {
    std::vector<int> peaks;
    int mountainLength = mountain.size(); //safes calculating time

    if (mountainLength == 0) return peaks; //if the array is empty
    for (int i = 1; i < mountainLength - 1; i++) {
        if (mountain[i] > mountain[i - 1] && mountain[i] > mountain[i + 1]) {peaks.push_back(i); i++;}
    }

    return peaks;
}



/**
 *  ========== Helper Functions ==========
 *
 *  void printDigits(vector<int>& digits)
 *  -> Prints the digits from the given vector as a decimal number
 *
 *  void printList(vector<int>& numbers)
 *  -> Prints the list
 *
 */



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

