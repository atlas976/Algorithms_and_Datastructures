#include "../include/blatt7.h"


/// exercise 2

// Return: The order the deletes elements, and the label of the surviving
std::pair<vector<int>, int> josephus(int n, int k)
{
    CyclicLinkedList cl(n);
    vector<int> order;
    Node *&node = cl.start; // Shift cl.start (Referenz!)
    while (node->next != node)
    { // as long as there is a different element
        // delete the k-th element after h (h is the 1.)
        // 1. go k-2 steps further
        for (int i = 0; i < k - 2; ++i)
            node = node->next;

        // 2. delete the next element
        Node *succ = node->next;
        node->next = succ->next;
        order.push_back(succ->data);
        delete succ;

        // and go one further
        node = node->next;
    }

    //return
    return {order, node->data};
}


/// exercise 3a)

float Polynomial::evaluate(float x) {
    //dec var
    float res = 0;

    //calc value of the polynom for x
    for (ListNode* currentNode = head; currentNode != nullptr; currentNode = currentNode->next) {
        res += currentNode->ci * pow(x, currentNode->i);
    }
    return res; //return the value of the polynom
}

/// exercise 3b)

bool Polynomial::equalTo(Polynomial& other){
    //pointer/var dec
    ListNode *currentNodeP1 = head;
    ListNode *currentNodeP2 = other.head;

    // one of the two polynomials is longer than the other
    //--> they are not the same!
    while (currentNodeP1 != nullptr || currentNodeP2 != nullptr) {
        if (currentNodeP1 == nullptr || currentNodeP2 == nullptr) {
            return false;
        }
        if ((currentNodeP1->i != currentNodeP2->i) || (currentNodeP1->ci != currentNodeP2->ci)) {
            return false;
        }
        currentNodeP1 = currentNodeP1->next;
        currentNodeP2 = currentNodeP2->next;
    }

    return true;
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
 *      float ci;                       Koefficient 
 *      ListNode* next;
 *  }
 *
 *  class Polynomial {
 *  public:
 *      ListNode* head;
 *      void print();
 */
