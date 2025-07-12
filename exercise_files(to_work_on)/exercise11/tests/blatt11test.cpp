#include <gtest/gtest.h>
#include <random>
#include <unordered_set>
#include "../include/blatt11.h"

typedef std::mt19937 MyRNG;
uint32_t seed_val = 738133946;
MyRNG rng;

int randomInt(int min, int max) {
    std::uniform_int_distribution<uint32_t> dist(min, max);
    return dist(rng);
}

std::string matrixToStr(const Matrix& numbers) {
    std::stringstream ss;
    std::string sep;
    for (const vector<int>& l: numbers) {
        ss << sep << listToString(l);
        sep = "\n";
    }
    return ss.str();
}


struct Params {
    static const int T_RANDOM = 0, T_BOUNDED_VALUES = 1, T_DOMINANT_ELEMENT = 2;
    int numElements, min, max, numIterations, listType{T_RANDOM};
};

vector<int> createList(int numElements, int min, int max, int factor=1) {
    vector<int> lst(numElements);
    for(int i = 0; i < numElements; i++) {
        lst[i] = randomInt(min, max);
        if(factor != 1) lst[i] *= factor;
    }
    return lst;
}

Matrix createMatrix(int numElements, int min, int max) {
    Matrix M;
    int lastMin = min;
    for(int i = 0; i < numElements; i++) {
        M.push_back(createList(numElements, lastMin, lastMin + 2 * max, 2));
        std::sort(M[i].begin(), M[i].end());
        lastMin = M[i][0];
    }

    for(int i = 1; i < numElements; i++) {
        for(int j = 0; j < numElements; j++) {
            int k = i;
            while(k > 0 && M[k][j] < M[k-1][j]) {
                std::swap(M[k][j], M[k-1][j]);
                k--;
            }
        }
    }
    return M;
}

BinarySearchTree createTree(int numElements, int min, int max) {
    BinarySearchTree bst;
    for(int i = 0; i < numElements; i++) {
        bst.insert(randomInt(min, max));
    }
    return bst;
}


class RemoveDuplicates : public testing::TestWithParam<Params> {};

TEST_P(RemoveDuplicates, RandomLists) {
    rng.seed(seed_val);
    Params params = GetParam();
    for(int i = 0; i < params.numIterations; i++) {
        vector<int> lst = createList(params.numElements, params.min, params.max);
        vector<int> output = withoutDuplicates(lst);
        std::unordered_set<int> st(lst.begin(), lst.end());
        if(output.size() != st.size()) {
            FAIL() << "False output on list: " << listToString(lst) << "\nYour Output:  " << listToString(output);
        }
        std::unordered_set<int> setFromOutput(output.begin(), output.end());
        if(st != setFromOutput) {
            FAIL() << "False output on list: " << listToString(lst) << "\nYour Output:  " << listToString(output);
        }
    }
}

class FindInMatrix : public testing::TestWithParam<Params> {};

TEST_P(FindInMatrix, RandomMatrix) {
    rng.seed(seed_val);
    Params params = GetParam();
    for(int rd = 0; rd < params.numIterations; rd++) {
        Matrix M = createMatrix(params.numElements, params.min, params.max);

        // Check some Elements that exist
        for(int _ = 0; _ < 5; _++) {
            int i = randomInt(0, params.numElements-1);
            int j = randomInt(0, params.numElements-1);
            bool exists = findInMatrix(M, M[i][j]);
            ASSERT_TRUE(exists) << "Cannot find existing Element " << M[i][j] << " at index " << i << ", " << j << "\n" << matrixToStr(M);
        }

        // Check some Elements that do not exist
        for(int _ = 0; _ < 5; _++) {
            int x = randomInt(0, M[params.numElements-1][params.numElements-1] / 2) * 2 + 1;
            bool exists = findInMatrix(M, x);
            ASSERT_FALSE(exists) << "Wrong Output: Element " << x << " does not exist in the Matrix." << "\n" << matrixToStr(M);
        }
    }
}


class BinaryTreeOperations : public testing::TestWithParam<Params> {};

TEST_P(BinaryTreeOperations, Count) {
    rng.seed(seed_val);
    Params params = GetParam();
    for(int rd = 0; rd < params.numIterations; rd++) {
        int n = randomInt(params.numElements / 2, params.numElements);
        BinarySearchTree bst = createTree(n, params.min, params.max);
        int cnt = count(bst.root);
        ASSERT_EQ(cnt, n) << "Wrong number of nodes counted.";
    }
}

int pl(TreeNode* n, int l) {
    if (n == nullptr) return 0;
    return l + pl(n->left, l + 1) + pl(n->right, l + 1);
}

TEST_P(BinaryTreeOperations, PathLength) {
    rng.seed(seed_val);
    Params params = GetParam();
    for(int rd = 0; rd < params.numIterations; rd++) {
        int n = randomInt(params.numElements / 2, params.numElements);
        BinarySearchTree bst = createTree(n, params.min, params.max);
        int path = pathLength(bst.root);
        int sl = pl(bst.root, 0);
        ASSERT_EQ(path, sl) << "Wrong Path Length.";
    }
}

INSTANTIATE_TEST_SUITE_P(
        ShortLists,
        RemoveDuplicates,
        testing::Values(Params{ 5, 0, 2, 25 })
);

INSTANTIATE_TEST_SUITE_P(
        LongLists,
        RemoveDuplicates,
        testing::Values(Params{ 25, 0, 8, 25 })
);

INSTANTIATE_TEST_SUITE_P(
        SmallMatrices,
        FindInMatrix,
        testing::Values(Params{ 3, 0, 25, 25 })
);

INSTANTIATE_TEST_SUITE_P(
        LargeMatrices,
        FindInMatrix,
        testing::Values(Params{ 10, 0, 200, 25 })
);

INSTANTIATE_TEST_SUITE_P(
        SmallTrees,
        BinaryTreeOperations,
        testing::Values(Params{ 5, 0, 20, 25 })
);

INSTANTIATE_TEST_SUITE_P(
        LargeTrees,
        BinaryTreeOperations,
        testing::Values(Params{ 50, 0, 500, 25 })
);
