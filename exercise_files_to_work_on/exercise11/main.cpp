#include <cstdio>
#include "include/blatt11.h"

void aufgabe2() {
    vector<int> A{5, 3, 7, 5, 9, 4, 0, 3, 5, 5, 2};
    printf("A: ");
    printList(A);
    vector<int> B = withoutDuplicates(A);
    printf("B: ");
    printList(B);
}

void aufgabe3() {
    Matrix M{{3, 4, 13}, {5, 7, 15}, {11, 12, 22}};
    printMatrix(M);
    bool exists = findInMatrix(M, 20);
    printf("Check for element 20: %d\n", exists);
}

void aufgabe4() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->left->right = new TreeNode(2);
    root->right = new TreeNode(5);

    int nodeCount = count(root);
    printf("Counted %d nodes in the tree.\n", nodeCount);

    int pl = pathLength(root);
    printf("Total Path length is %d\n", pl);

    delete root->right;
    delete root->left->right;
    delete root->left;
    delete root;
}

int main() {
    aufgabe2();
//    aufgabe3();
//    aufgabe4();
}
