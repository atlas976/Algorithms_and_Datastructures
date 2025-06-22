#include "../include/blatt7.h"


/// exercise 2

// Return: The order the deletes elements, and the label of the surviving
std::pair<vector<int>, int> josephus(int n, int k) {
    vector<int> order;
    // TODO
    return {order, 1};
}

/// exercise 3a)

float Polynomial::evaluate(float x) {
    float res = 0;
    // TODO
    return res;
}

/// exercise 3b)

bool Polynomial::equalTo(Polynomial& other){
    // TODO
    return false;
}


/**
 *  ========== Helpfunctions ==========
 *
 *  void printList(vector<int>& numbers)
 *  -> Prints List
 *
 *
 *  - - - - - - - - - - - - - for exercise 2) Josephus - - - - - - - - - - - - - - - - - - - - -
 *  struct Node {                       Represents an element in a CyclicLinkedList
 *      int data;
 *      Node* next;
 *  }
 *
 *  class CyclicLinkedList {
 *  public:
 *      Node* start;
 *      CyclicLinkedList(int count);    Initialises with count Vertices, beginning with data = 1
 *      ~CyclicLinkedList()             Deletes all left items
 *      void print();                   Prints the List
 *  }
 *
 *  - - - - - - - - - - - - - Für Aufgabe 3) Polynome - - - - - - - - - - - - - - - - - - - - -
 *  struct ListNode {                   Represents an element in a Polynom: ci * x^i
 *      int i;                          Exponent
 *      float ci;                       Koeffizient //<-- english missing
 *      ListNode* next;
 *  }
 *
 *  class Polynomial {
 *  public:
 *      ListNode* head;
 *      void print();
 */
