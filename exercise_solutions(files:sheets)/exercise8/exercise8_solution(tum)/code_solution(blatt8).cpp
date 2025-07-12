#include "../include/blatt8.h"

/// Aufgabe 3
int max_subarray(vector<int>& a, int l, int r) {
    if (l >= r) return a[l];
    int m = l + (r-l) / 2;
    int best_left = max_subarray(a, l, m);
    int best_right = max_subarray(a, m + 1, r);

    int leftside = 0, maxleft = 0;
    for (int i = m-1; i >= l; --i) {
        leftside += a[i];
        if (leftside > maxleft) maxleft = leftside;
    }

    int rightside = 0, maxright = 0;
    for (int i = m+1; i <= r; ++i) {
        rightside += a[i];
        if (rightside > maxright) maxright = rightside;
    }
    int res = a[m] + maxleft + maxright;

    if (best_left > res) res = best_left;
    if (best_right > res) res = best_right;
    return res;
}


int max_subarray(vector<int>& a) {
    if(a.empty()) return 0;
    return max_subarray(a, 0, a.size()-1);
}


/// Aufgabe 4a)
void Polynomial::flip() {
    for (ListNode* node = head; node != nullptr; node = node->next) {
        node->ci *= -1;
    }
}


/// Aufgabe 4b)
void moveUpRec(ListNode* &node, float c) {
    if(node == nullptr) {
        // es gibt kein Element für den Fall Exponent == 0, wir fügen eins ein
        node = new ListNode(0, c);
        return;
    }

    if(node->next != nullptr) {
        // wir sind noch nicht das letzte Element -> Aufruf an next weitergeben
        moveUpRec(node->next, c);
        return;
    }

    // wenn wir das hier erreichen, ist node das letzte Element
    if(node->i == 0) {
        // node ist bereits Element mit Exponent == 0
        if(node->ci == -c) {
            ListNode* tmp = node;
            node = nullptr;
            delete tmp;
        } else {
            node->ci += c; // wir müssen nur den Offset addieren
        }
    } else {
        // es gibt kein Element für den Fall Exponent == 0, wir fügen eins ein
        node->next = new ListNode(0, c);
    }
}

void Polynomial::moveUp(float c) {
    if(head == nullptr) head = new ListNode(0, c);
    else moveUpRec(head, c);
}


/// Aufgabe 4c)
void add_rec(ListNode* &current, ListNode* other) {
    // Basisfall: Eins der beiden Polynome ist zu Ende
    if(other == nullptr)
        return;

    if(current == nullptr) {
        // Unser Polynom ist zu Ende
        current = new ListNode(other->i, other->ci);
        add_rec(current->next, other->next);
        // Wichtig: andere Liste muss KOPIERT werden:
        // "current = other;" wäre fatal, da es beide Listen zusammenführen würde!
        return;
    }

    // Rekursionsfall: Es gibt 3 Möglichkeiten, basierend darauf welcher Exponent der größte ist:
    if(current->i > other->i) {
        // Unser Exponent is höher -> wir gehen einen Schritt weiter
        add_rec(current->next, other);
    } else if (current->i < other->i) {
        // Der andere Exponent is höher -> wir kopieren das Element in unsere Liste
        ListNode* node = new ListNode(other->i, other->ci);
        node->next = current;
        current = node;
        add_rec(node->next, other->next);
    } else {
        // Jetzt gilt: current->i == other->i
        // -> Wir addieren die Koeffizienten
        current->ci += other->ci;
        if(current->ci == 0) {
            // Die Summe der Koeffizienten ist 0 -> Wir löschen den Knoten
            ListNode* tmp = current; // Pointer auf current, um diesen Knoten löschen zu können
            current = current->next;
            delete tmp;
            add_rec(current, other->next);
        } else {
            add_rec(current->next, other->next);
        }
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
