#include "../include/blatt8.h"

/// Aufgabe 3
int max_subarray(vector<int>& a) {
    // TODO
    return 0;
}

/// Aufgabe 4a)
void Polynomial::flip() {
    // TODO
}

/// Aufgabe 4b)
void Polynomial::moveUp(float c) {
    // TODO
}

/// Aufgabe 4c)
void Polynomial::add(Polynomial& other){
    // TODO
}


/**
 *  ========== Hilfsfunktionen ==========
 *
 *  void printList(vector<int>& numbers)
 *  -> Gibt die Liste aus
 *
 *
 *  - - - - - - - - - - - - - Für Aufgabe 3) Polynome - - - - - - - - - - - - - - - - - - - - -
 *  struct ListNode {                   Repräsentiert ein Element in einem Polynom: ci * x^i
 *      int i;                          Exponent
 *      float ci;                       Koeffizient
 *      ListNode* next;
 *      ListNode(int exp, float coeff); Erstellt eine ListNode mit gegebenem Exponenten und Koeffizienten
 *  }
 *
 *  class Polynomial {
 *  public:
 *      ListNode* head;
 *      void print();
 */
