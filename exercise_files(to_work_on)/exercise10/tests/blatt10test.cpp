#include <gtest/gtest.h>
#include <random>
#include "../include/blatt10.h"

typedef std::mt19937 MyRNG;
uint32_t seed_val = 75823946;
MyRNG rng;

int randomInt(int min, int max) {
    std::uniform_int_distribution<uint32_t> dist(min, max);
    return dist(rng);
}

std::string listToString(const vector<int>& lst) {
    std::stringstream ss;
    std::string sep;
    for (int i: lst) {
        ss << sep << i;
        sep = ", ";
    }
    return ss.str();
}

struct Params {
    static const int T_RANDOM = 0, T_BOUNDED_VALUES = 1, T_DOMINANT_ELEMENT = 2;
    int numElements, min, max, numIterations, listType{T_RANDOM};
};

using D = std::unordered_map<int, int>;

vector<int> createList(int numElements, int min, int max, int type) {
    vector<int> lst;
    int elem = randomInt(min, max);
    switch (type) {
        case Params::T_DOMINANT_ELEMENT:
            for(int i = 0; i < numElements / 2 + 1; i++)
                lst.push_back(elem);
            for(int i = lst.size(); i < numElements; i++) {
                int ix = randomInt(0, lst.size());
                lst.insert(lst.begin() + ix, randomInt(min, max));
            }
            break;
        case Params::T_BOUNDED_VALUES:
            max = numElements;
        case Params::T_RANDOM: default:
            for(int i = 0; i < numElements; i++) {
                lst.push_back(randomInt(min, max));
            }
            break;
    }
    return lst;
}

class Majority : public testing::TestWithParam<Params> {};

TEST_P(Majority, RandomLists) {
    rng.seed(seed_val);
    D data;
    Params params = GetParam();
    int (*func)(const vector<int>&);
    switch (params.listType) {
        case Params::T_RANDOM: func = majority; break;
        case Params::T_BOUNDED_VALUES: func = majorityBoundedValues; break;
        case Params::T_DOMINANT_ELEMENT: func = majorityDominantElement; break;
    }
    for(int i = 0; i < params.numIterations; i++) {
        vector<int> lst = createList(params.numElements, params.min, params.max, params.listType);
        int best{0};
        data.clear();
        for(const auto& x: lst) best = std::max(best, ++data[x]);
        int maj = func(lst);
        bool isMax = data[maj] == best;
        ASSERT_TRUE(isMax) << "False output on list: " << listToString(lst);
    }
}

INSTANTIATE_TEST_SUITE_P(
        General_ShortLists,
        Majority,
        testing::Values(Params{ 5, 0, 2, 25 })
);

INSTANTIATE_TEST_SUITE_P(
        General_HighValues,
        Majority,
        testing::Values(Params{ 5, 574382, 574384, 25 })
);

INSTANTIATE_TEST_SUITE_P(
        General_LongLists,
        Majority,
        testing::Values(Params{ 20, 0, 5, 25 })
);

INSTANTIATE_TEST_SUITE_P(
        BoundedValues_ShortLists,
        Majority,
        testing::Values(Params{ 5, 0, 0, 25, Params::T_BOUNDED_VALUES })
);

INSTANTIATE_TEST_SUITE_P(
        BoundedValues_LongLists,
        Majority,
        testing::Values(Params{ 20, 0, 0, 25, Params::T_BOUNDED_VALUES })
);

INSTANTIATE_TEST_SUITE_P(
        DominantElement_ShortLists,
        Majority,
        testing::Values(Params{ 5, 0, 2, 25, Params::T_DOMINANT_ELEMENT })
);

INSTANTIATE_TEST_SUITE_P(
        DominantElement_HighValues,
        Majority,
        testing::Values(Params{ 5, 574382, 574384, 25, Params::T_DOMINANT_ELEMENT })
);

INSTANTIATE_TEST_SUITE_P(
        DominantElement_LongLists,
        Majority,
        testing::Values(Params{ 20, 0, 5, 25, Params::T_DOMINANT_ELEMENT })
);