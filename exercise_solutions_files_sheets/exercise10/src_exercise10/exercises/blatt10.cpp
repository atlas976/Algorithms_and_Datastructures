#include "../include/blatt10.h"
#include <map>

using namespace std;

// This function will receive completely random lists in the TestSuite
int majority(const vector<int>& A){
    if (A.empty()) {
        return -1; // or throw, depending on requirements
    }
    std::map<int, int> dictionary;
    for (int num : A) {
        dictionary[num]++;
    }
    int max_count = 0;
    int majority_element = -1;
    for (const auto& pair : dictionary) {
        if (pair.second > max_count) {
            max_count = pair.second;
            majority_element = pair.first;
        }
    }
    return majority_element;
}

// This function will receive lists with bounded values in the TestSuite
// It holds A[i] <= A.length for all i
int majorityBoundedValues(const vector<int>& A){
    // TODO
    return 0;
}

// This function will receive lists with a dominant element in the TestSuite
// There exists an element that occurs at least A.length / 2 times
int majorityDominantElement(const vector<int>& A){
    // TODO
    return 0;
}


/**
 *  ========== Helperfunctions ==========
 *
 * void printList(vector<int>& numbers)
 *  -> Prints the list
 *
 */
