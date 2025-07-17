#include "../include/blatt7.h"


/// Aufgabe 2

// Return: Die Reihenfolge der entfernten Elemente, und das Label des Überlebenden
std::pair<vector<int>, int> josephus(int n, int k) {
    vector<int> order;
    // TODO
    return {order, 1};
}

/// Aufgabe 3a)

float Polynomial::evaluate(float x) {
    float res = 0;
    // TODO
    return res;
}

/// Aufgabe 3b)

bool Polynomial::equalTo(Polynomial& other){
    // TODO
    return false;
}


/**
 *  ========== Hilfsfunktionen ==========
 *
 *  void printList(vector<int>& numbers)
 *  -> Gibt die Liste aus
 *
 *
 *  - - - - - - - - - - - - - Für Aufgabe 2) Josephus - - - - - - - - - - - - - - - - - - - - -
 *  struct Node {                       Repräsentiert ein Element in einer CyclicLinkedList
 *      int data;
 *      Node* next;
 *  }
 *
 *  class CyclicLinkedList {
 *  public:
 *      Node* start;
 *      CyclicLinkedList(int count);    Initialisiert mit count Knoten, beginnend mit data = 1
 *      ~CyclicLinkedList()             Löscht alle verbleibenden Elemente
 *      void print();                   Gibt die Liste aus
 *  }
 *
 *  - - - - - - - - - - - - - Für Aufgabe 3) Polynome - - - - - - - - - - - - - - - - - - - - -
 *  struct ListNode {                   Repräsentiert ein Element in einem Polynom: ci * x^i
 *      int i;                          Exponent
 *      float ci;                       Koeffizient
 *      ListNode* next;
 *  }
 *
 *  class Polynomial {
 *  public:
 *      ListNode* head;
 *      void print();
 */
