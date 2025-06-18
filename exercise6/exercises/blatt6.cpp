#include "../include/blatt6.h"

// exercise 2
// constant is setting the maximum values of n and k
constexpr int N = 1000;

long long binom_memo(const int n, const int k) { // NOLINT(*-no-recursion)
    //create lookup
    std::vector<long long> lookup(n + 1, 0);  // Initialisiert mit 0 (macht das gleiche wie: long long lookup[n] = {}
                                                 // nur das es funktioniert, da in C++ die var zur compilerzeit zur dek des
    //check lookup                               // array bekannt sein muss.
    if (lookup[n] > 0) {
        return lookup[n];
    }
    //base case
    if (k == n || k == 0) {
        return 1;
    }
    //rec case
    lookup[n] = binom_memo(n - 1, k - 1) + binom_memo(n - 1, k);
    return lookup[n];
}


//exercise 3 help functions
std::pair<int, int> findMinAndIndex(vector<int>& vec, int k) {
    int low = INT_MAX;
    int lowIndex = 0;
    for (k; k < vec.size(); k++) {
        if (vec[k] < low) {
            low = vec[k];
            lowIndex = k;
        }
    }
    return {low, lowIndex};
}


void selection_sort_rec(vector<int>& vec, int i) {
    int buf = 0;

    //base case
    if (i == vec.size()) {
        return;
    }

    //rec case
    const std::pair<int, int> MinAndIndex = findMinAndIndex(vec, i);
    buf = vec[i];
    vec[i] = MinAndIndex.first;
    vec[MinAndIndex.second] = buf;
    selection_sort_rec(vec, i + 1);
}


//exercise 3
void selection_sort(vector<int>& vec) {
    selection_sort_rec(vec, 0);
}


//exercise 4a
int search(vector<int>& vec, int c, int x) {
    int n = vec.size();
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        // calc index in shifted vec
        int shiftedMid = (mid + c) % n;

        if (vec[shiftedMid] == x) {
            return shiftedMid;
        } else if (vec[shiftedMid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    // not found
    return -1;
}

//exercise 4b
int get_shift(vector<int>& vec) {
    int n = vec.size();
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int mid = (left + right) / 2;

        if (vec[mid] > vec[right]) {
            // Minimum is at the right of it
            left = mid + 1;
        } else {
            // Minimum is mid or left of it
            right = mid;
        }
    }

    // left == Index of Min== count of shifts to the right
    return left;
}



/**
 *  ========== Helperfunction ==========
 *
 *  void printList(vector<int>& numbers)
 *  -> Prints the List
 *
 */
