#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_set>

#ifndef PROGRAMMIERAUFGABEN_BLATT0_H
#define PROGRAMMIERAUFGABEN_BLATT0_H

using std::vector, std::unordered_set;

using Matrix = vector<vector<int>>;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    explicit TreeNode(int v) {
        val = v;
        left = right = nullptr;
    }
};

class BinarySearchTree {
public:
    TreeNode* root;

    BinarySearchTree() {
        root = nullptr;
    }
    ~BinarySearchTree(){
        cleanup(root);
    }
    void insert(int val) {
        insert(val, root);
    }
private:
    void cleanup(TreeNode* node) {
        if(node == nullptr) return;
        cleanup(node->left);
        cleanup(node->right);
        delete node;
    }

    void insert(int val, TreeNode* &node) {
        if(node == nullptr) {
            node = new TreeNode(val);
            return;
        }

        if(val < node->val) {
            insert(val, node->left);
        } else {
            insert(val, node->right);
        }
    }
};

template<typename T>
vector<T> sorted(const vector<T>& in) {
    vector<T> other(in);
    std::sort(other.begin(), other.end());
    return other;
}

vector<int> withoutDuplicates(const vector<int>&);

bool findInMatrix(const Matrix& M, int elem);

int count(TreeNode* node);

int pathLength(TreeNode* node);

/// Hilfsfunktionen
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

static void printMatrix(const Matrix& numbers) {
    std::stringstream ss;
    std::string sep;
    for (const vector<int>& l: numbers) {
        ss << sep << listToString(l);
        sep = "\n";
    }
    printf("%s\n", ss.str().c_str());
}


#endif //PROGRAMMIERAUFGABEN_BLATT0_H
