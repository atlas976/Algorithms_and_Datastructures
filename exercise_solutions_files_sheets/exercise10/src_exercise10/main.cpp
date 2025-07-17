#include <cstdio>
#include "include/blatt10.h"

void aufgabe2() {
    vector<int> list{5,4,4,3,5,5,6,5,4,3,4,5,4,3,4,3,5,4};
    printList(list);
    int maj = majority(list);
    printf("Most frequent element:  %d\n", maj);
}
  
int main() {
    aufgabe2();
}
