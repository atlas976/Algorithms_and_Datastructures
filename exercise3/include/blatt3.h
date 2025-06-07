//
// Created by Robin on 25.03.24.
//

#include <sstream>
#include <vector>
#include <set>

#ifndef PROGRAMMIERAUFGABEN_BLATT1_H
#define PROGRAMMIERAUFGABEN_BLATT1_H

using std::vector, std::set;

int max_subarray(vector<int>& a);

vector<int> examRoomOrder(int n);

static void printList(vector<int>& numbers) {
    std::stringstream ss;
    std::string sep;
    for (int i: numbers) {
        ss << sep << i;
        sep = ", ";
    }
    printf("%s\n", ss.str().c_str());
}


#endif //PROGRAMMIERAUFGABEN_BLATT1_H
