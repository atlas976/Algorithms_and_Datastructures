#include <vector>
#include <sstream>

#ifndef PROGRAMMIERAUFGABEN_BLATT0_H
#define PROGRAMMIERAUFGABEN_BLATT0_H

using std::vector;

int majority(const vector<int>&);

int majorityBoundedValues(const vector<int>&);

int majorityDominantElement(const vector<int>&);

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
