#include "../include/blatt7.h"


/// Aufgabe 2

// Return: Die Reihenfolge der entfernten Elemente, und das Label des Überlebenden
std::pair<vector<int>, int> josephus(int n, int k) {
    vector<int> order;

    // TODO: CyclicLinked List (cl) erstellen

    // TODO: Pointer auf Start von cl anlegen (node), der es uns erlaubt cl.start zu verschieben (Referenz!)

    while (/* TODO: solange cl nicht leer */) {
        // Lösche das k-te Element nach h (h ist das 1.)
        // TODO 1) Schiebe node um k-2 Schritte weiter

        // TODO 2) Lösche das Nachfolge-Element von node, und speichere es in order ab

        // TODO 3) Schiebe node (und damit auch cl.start) um eins weiter.
    }

    // TODO: Gib order und das Label des Überlebenden zurück.
    //  Entweder mit return std::make_pair(p1, p2), oder einfach return {p1, p2};
    return {order, 1};
}

/// Aufgabe 3a)

float Polynomial::evaluate(float x) {
    float res = 0;
    // TODO: iteriere durch die LinkedList, lege dafür einen Pointer auf den head an
    //  und folge dem next Pointer solange, bis er zum nullptr wird
    for (/* TODO */) {
        // TODO: berechne x^i mit der std::pow Funktion
        // TODO: multipliziere mit Koeffizienten und addiere zu Ergebnis
    }
    return res;
}

/// Aufgabe 3b)

bool equal_rec(ListNode* x, ListNode* y) {
    // TODO: falls beide Listen leer sind, dann sind sie gleich und wir geben true zurück

    // TODO: falls genau eine Liste nicht leer ist, oder falls i oder ci nicht
    //  übereinstimmen, dann sind die Polynome nicht gleich. Dann geben wir false zurück

    // TODO: sonst vergleiche rekursiv die Teillisten x->next und y->next (gehe in den Listen einen Schritt weiter)
}

bool Polynomial::equalTo(Polynomial& other){
    // Wir verwenden eine rekursive Hilfsfunktion
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
