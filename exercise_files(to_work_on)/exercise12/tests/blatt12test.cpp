#include <gtest/gtest.h>
#include <random>
#include <unordered_set>
#include "../include/blatt12.h"

typedef std::mt19937 MyRNG;
uint32_t seed_val = 738133946;
MyRNG rng;

int randomInt(int min, int max) {
    std::uniform_int_distribution<uint32_t> dist(min, max);
    return dist(rng);
}

vector<int> createRandomList(int numElements, int min, int max, int factor=1) {
    vector<int> lst(numElements);
    for(int i = 0; i < numElements; i++) {
        lst[i] = randomInt(min, max);
        if(factor != 1) lst[i] *= factor;
    }
    return lst;
}

vector<int> createValidKeySequence(int numElements, int min, int max, int key) {
    vector<int> lst;
    lst.push_back(randomInt(min, max));
    for(int i = 0; i < numElements-1; ++i) {
        if(key > lst.at(i))
            min = lst.at(i)+1;
        else max = lst.at(i)-1;
        if(min >= max) break;
        lst.push_back(randomInt(min, max));
        if(lst.at(i+1) == key) {
            lst.pop_back(); break;
        }
    }
    return lst;
}


vector<int> createInvalidKeySequence(int numElements, int min, int max) {
    vector<int> lst = createRandomList(numElements, min, max);
    int key = lst.back();
    int wrongPlaces = std::min(randomInt(1, lst.size() / 3), 1);
    for(int i = 0; i < wrongPlaces; ++i) {
        int ixLeft = randomInt(0, lst.size()-3);
        int pos = lst.at(ixLeft);
        int ixRight = randomInt(ixLeft + 1, lst.size()-2);
        if(pos > key) {
            lst.at(ixRight) = pos + (max - pos) / 2 + 1;
        } else {
            lst.at(ixRight) = pos - (pos / 2) - 1;
        }
    }
    return lst;
}

struct Params {
    static const int T_RANDOM = 0, T_BOUNDED_VALUES = 1, T_DOMINANT_ELEMENT = 2;
    int numElements, min, max, numIterations, listType{T_RANDOM};
};

class KeySequence : public testing::TestWithParam<Params> {};

TEST_P(KeySequence, ValidSequences) {
    rng.seed(seed_val);
    Params params = GetParam();
    for(int i = 0; i < params.numIterations; i++) {
        int span = params.max - params.min;
        int key = randomInt(span / 4, params.max - span / 4);
        vector<int> lst = createValidKeySequence(params.numElements, params.min, params.max, key);
        lst.push_back(key);
        printList(lst);
        bool exists = treeExists(lst);
        ASSERT_TRUE(exists) << "False output on valid key sequence: " << listToString(lst) << "\n";
    }
}

TEST_P(KeySequence, InvalidSequences) {
    rng.seed(seed_val);
    Params params = GetParam();
    for(int i = 0; i < params.numIterations; i++) {
        vector<int> lst = createInvalidKeySequence(params.numElements, params.min, params.max);
        printList(lst);
        bool exists = treeExists(lst);
        ASSERT_FALSE(exists) << "False output on invalid key sequence: " << listToString(lst) << "\n";
    }
}

INSTANTIATE_TEST_SUITE_P(
        ShortLists,
        KeySequence,
        testing::Values(Params{ 5, 0, 100, 25 })
);

INSTANTIATE_TEST_SUITE_P(
        LongLists,
        KeySequence,
        testing::Values(Params{ 50, 0, 1000000, 50 })
);

