//
// Created by Robin on 25.03.24.
//

#include <vector>
#include <sstream>

#ifndef PROGRAMMIERAUFGABEN_BLATT0_H
#define PROGRAMMIERAUFGABEN_BLATT0_H

using std::vector;
using vector_iterator = vector<int>::iterator;

long long binom_memo(int, int);

void selection_sort(vector<int>&);

int search(vector<int>&, int, int);

int get_shift(vector<int>&);

static void printList(vector<int>& numbers) {
    std::stringstream ss;
    std::string sep;
    for (int i: numbers) {
        ss << sep << i;
        sep = ", ";
    }
    printf("%s\n", ss.str().c_str());
}

#endif //PROGRAMMIERAUFGABEN_BLATT0_H
