#include "../include/blatt8.h"
#include <iostream>
#include <climits>

using namespace std;


//review has to be done
// exercise 3
// Interne Hilfsfunktion (rekursiv)
int maxSubarrayHelper(const vector<int> &a, int left, int right)
{
    if (left == right)
    {
        return a[left];
    }

    int mid = (left + right) / 2;

    int left_sum = maxSubarrayHelper(a, left, mid);
    int right_sum = maxSubarrayHelper(a, mid + 1, right);

    // Über die Mitte hinweg
    int left_cross_sum = INT_MIN, sum = 0;
    for (int i = mid; i >= left; --i)
    {
        sum += a[i];
        left_cross_sum = max(left_cross_sum, sum);
    }

    int right_cross_sum = INT_MIN;
    sum = 0;
    for (int i = mid + 1; i <= right; ++i)
    {
        sum += a[i];
        right_cross_sum = max(right_cross_sum, sum);
    }

    int cross_sum = left_cross_sum + right_cross_sum;

    return max({left_sum, right_sum, cross_sum});
}

// Öffentliche Funktion: nur das Array
int max_subarray(vector<int> &a)
{
    if (a.empty())
        return 0; // oder INT_MIN, je nach Definition
    return maxSubarrayHelper(a, 0, a.size() - 1);
}



/// exercise 4a)
void Polynomial::flip() 
{
    //multiply all coefficients by -1, so the it is flipped at the x-axis
    for (ListNode *currentNode = head; currentNode != nullptr; currentNode = currentNode->next) 
    {
        currentNode->ci *= -1;
        //currentNode->i *= -1;
    }
}

/// exercise 4b)
void Polynomial::moveUp(float c) 
{
    if (c == 0) return; //nothing to do
    if (head == nullptr) 
    { //insert the constant, no polynom is there yet
        head = new ListNode(0, c);
        return;
    }
    //dex (help)pointer
    ListNode* currentNode = head;
    ListNode* prevNode = nullptr;

    while (currentNode != nullptr) 
    {
        if (currentNode->i == 0) 
        {
            currentNode->ci += c; //add up the constant
            // remove node if coefficient is now zero
            if (currentNode->ci == 0) 
            {
                if (prevNode) prevNode->next = currentNode->next;
                else head = currentNode->next;
                delete currentNode;
            }
            return;
        }
        //advance pointers
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
    // No constant term found, add at end
    prevNode->next = new ListNode(0, c);
}

//exercise 4c)
void Polynomial::add(Polynomial &other)
{
    ListNode *P1 = head;
    ListNode *P2 = other.head;
    ListNode *prev = nullptr;

    while (P1 != nullptr && P2 != nullptr)
    {
        if (P1->i > P2->i)
        {
            // P1 exponent is greater → keep moving forward in P1
            prev = P1;
            P1 = P1->next;
        }
        else if (P1->i < P2->i)
        {
            // Insert new node from P2 before P1
            ListNode *newNode = new ListNode(P2->i, P2->ci);
            if (newNode->ci == 0)
            {
                delete newNode;
                P2 = P2->next;
                continue;
            }

            newNode->next = P1;
            if (prev == nullptr)
            {
                head = newNode;
            }
            else
            {
                prev->next = newNode;
            }
            prev = newNode;
            P2 = P2->next;
        }
        else
        {
            // Same exponent → add coefficients
            P1->ci += P2->ci;
            if (P1->ci == 0)
            {
                // Remove P1 node
                ListNode *toDelete = P1;
                if (prev == nullptr)
                {
                    head = P1->next;
                    P1 = head;
                }
                else
                {
                    prev->next = P1->next;
                    P1 = prev->next;
                }
                delete toDelete;
            }
            else
            {
                prev = P1;
                P1 = P1->next;
            }
            P2 = P2->next;
        }
    }

    // Append remaining nodes from P2
    while (P2 != nullptr)
    {
        if (P2->ci != 0)
        {
            ListNode *newNode = new ListNode(P2->i, P2->ci);
            if (prev == nullptr)
            {
                head = newNode;
                prev = newNode;
            }
            else
            {
                prev->next = newNode;
                prev = newNode;
            }
        }
        P2 = P2->next;
    }
}

    /**
     *  ========== Helpfunctions ==========
     *
     *  void printList(vector<int>& numbers)
     *  -> Prints the List
     *
     *
     *  - - - - - - - - - - - - - For exercise 3) Polynome - - - - - - - - - - - - - - - - - - - - -
     *  struct ListNode {                   represents an element in a Polynom: ci * x^i
     *      int i;                          Exponent
     *      float ci;                       Koefficient
     *      ListNode* next;
     *      ListNode(int exp, float coeff); Erstellt eine ListNode mit gegebenem Exponenten und Koeffizienten
     *  }
     *
     *  class Polynomial {
     *  public:
     *      ListNode* head;
     *      void print();
     */
