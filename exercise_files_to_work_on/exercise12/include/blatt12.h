#include <vector>
#include <sstream>
#include <algorithm>

#ifndef PROGRAMMIERAUFGABEN_BLATT0_H
#define PROGRAMMIERAUFGABEN_BLATT0_H

using std::vector;

bool treeExists(const vector<int>& sequence);

static void printList(const vector<int>& numbers) {
    std::stringstream ss;
    std::string sep;
    for (int i: numbers) {
        ss << sep << i;
        sep = ", ";
    }
    printf("%s\n", ss.str().c_str());
}

static std::string listToString(const vector<int>& lst) {
    std::stringstream ss;
    std::string sep;
    for (int i: lst) {
        ss << sep << i;
        sep = ", ";
    }
    return ss.str();
}

#endif //PROGRAMMIERAUFGABEN_BLATT0_H
