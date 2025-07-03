#include "../include/blatt8.h"

/// Aufgabe 3
int max_subarray(vector<int>& a) {
    



    return 0;
}
 
/// Aufgabe 4a)
void Polynomial::flip() {
    //multiply all coefficients by -1, so the it is flipped at the x-axis
    for (ListNode *currentNode = head; currentNode != nullptr; currentNode = currentNode->next) {
        currentNode->ci *= -1;
        //currentNode->i *= -1;
    }
}

/// Aufgabe 4b)
void Polynomial::moveUp(float c) {
    //dec pointer
    ListNode* currentNode = head; 
    if (head == nullptr) { // if list is empty return
        return;
    }
    if (c == 0) {
        return;
    }
    //hangle to the last element of the list
    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }
    if (currentNode->i == 0) { //if the last element is the konstant term of the poly
        currentNode->ci += c; 
    }
    else { //if it is not
        currentNode->next = new ListNode(0, c);
    }
}

/// Aufgabe 4c)
void Polynomial::add(Polynomial& other){
    // pointer/var dec
    ListNode *currentNodeP1 = head;
    ListNode *currentNodeP2 = other.head;
    ListNode *bufferNode;
    // one of the two polynomials is longer than the other
    //--> they are not the same!
    while (currentNodeP1 != nullptr || currentNodeP2 != nullptr)
    {
        if (currentNodeP1->i < currentNodeP2->i && currentNodeP1 == head) { //if other is longer than poly
            bufferNode = currentNodeP2->next;
            currentNodeP2->next = head;
            head = currentNodeP2;
            currentNodeP2 = bufferNode;
        }
        
    }
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
