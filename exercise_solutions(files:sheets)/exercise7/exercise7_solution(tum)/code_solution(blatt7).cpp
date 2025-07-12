#include "../include/blatt7.h"


/// Aufgabe 2

// Return: Die Reihenfolge der entfernten Elemente, und das Label des Überlebenden
std::pair<vector<int>, int> josephus(int n, int k) {
    CyclicLinkedList cl(n);
    vector<int> order;
    Node* &node = cl.start; // Wir verschieben cl.start (Referenz!)
    while (node->next != node) {  //solange noch ein anderes Element da ist
        //Lösche das k-te Element nach h (h ist das 1.)
        //1. Gehe k-2 Schritte weiter
        for (int i = 0; i < k - 2; ++i)
            node = node->next;

        //2. Lösche das nächste Element
        Node *succ = node->next;
        node->next = succ->next;
        order.push_back(succ->data);
        delete succ;

        //und gehe eins weiter
        node = node->next;
    }
    return {order, node->data};
}

/// Aufgabe 3a)

float Polynomial::evaluate(float x) {
    float res = 0;
    // iteriere durch die LinkedList, aktuelle ListNode im Pointer node
    for (ListNode* node = head; node != nullptr; node = node->next) {
        float xpowj = std::pow(x, node->i);
        // multipliziere mit Koeffizienten und addiere zu Ergebnis
        res += node->ci * xpowj;
    }
    return res;
}

/// Aufgabe 3b)

bool equal_rec(ListNode* x, ListNode* y) {
    //falls beide Listen leer sind, dann sind die gleich
    if (x == nullptr && y == nullptr) return true;
    // falls genau eine Liste nicht leer ist, oder falls i oder ci nicht
    // übereinstimmen, dann sind die Polynome nicht gleich
    if (x == nullptr || y == nullptr || x->i != y->i || x->ci != y->ci) return false;
    // sonst vergleiche die Teillisten x->next und y->next (gehe in den Listen einen Schritt weiter)
    return equal_rec(x->next, y->next);
}

bool Polynomial::equalTo(Polynomial& other){
    return equal_rec(head, other.head);
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
