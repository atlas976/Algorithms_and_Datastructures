#include <cstdio>
#include "include/blatt12.h"

void aufgabe1() {
    vector<int> sequence{20, 70, 47, 48, 53, 54};
    printf("Key Sequence: ");
    printList(sequence);
    bool exists = treeExists(sequence);
    if(exists) printf(" -> Search Tree exists!");
    else printf(" -> Search Tree does not exist!");
}

int main() {
    aufgabe1();
}
