#include "../include/blatt8.h"


/// Aufgabe 4b)
void moveUpRec(ListNode* &node, float c) {
    if(/* Base Case 1: node points behind the end of the list */) {
        // TODO: insert new element at end of list, overwriting the pointer to node.
    }

    if(/* Base Case 2: node points at element which is not the final valid element of the list */) {
        // TODO: pass the call along to the next element
    }

    // We only reach this point if node is the final valid element of the list

    if(/* node points to element corresponding to the constant term of the polynomial */) {
        // TODO: add offset to coefficient

        // TODO: if coefficient has now become 0, we need to remove the element. Overwrite the node pointer and free the memory.
    } else {
        // TODO: insert a new element for the constant term
    }
}

void Polynomial::moveUp(float c) {
    // TODO: handle case when head == nullptr

    // TODO: call recursive helper function
}


/// Aufgabe 4c)

void add_rec(ListNode* &current, ListNode* other) {
    // 1) Base Case: One of the Polynomials is empty

    // TODO: if our polynomial is empty, recursively copy the rest of the other

    // 2) Recursion: There are three possibilities, based on which exponent is larger
    if(current->i > other->i) {
        // TODO: our exponent is larger -> go to next element
    } else if (current->i < other->i) {
        // TODO: the other exponent is larger -> we copy the element into our list, make sure to set all pointers properly.
    } else {
        // now: current->i == other->i
        // TODO: add coefficients

        // TODO: if coefficient has become 0 -> delete the node. Make sure to free the memory and fix the pointers
        // TODO: then make the proper recursive call on the next elements
    }
}

void Polynomial::add(Polynomial& other){
    add_rec(head, other.head);
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
