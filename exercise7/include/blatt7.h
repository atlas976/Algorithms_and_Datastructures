//
// Created by Robin on 25.03.24.
//

#include <cmath>
#include <vector>
#include <sstream>

#ifndef PROGRAMMIERAUFGABEN_BLATT0_H
#define PROGRAMMIERAUFGABEN_BLATT0_H

using std::vector;

using PolynomialParams = vector<std::pair<int, float>>;

struct ListNode {
    int i;
    float ci;
    ListNode *next;

    ListNode(int exp, float coeff) {
        i = exp;
        ci = coeff;
        next = nullptr;
    }

    [[nodiscard]] std::string ppr() const {
        std::stringstream ss;
        if(next != nullptr) ss << next->ppr() << ", ";
        ss << "{" << i << ", " << ci << "}";
        return ss.str();
    }
};

class Polynomial {
public:
    ListNode *head{nullptr};

    explicit Polynomial(PolynomialParams& elems) {
        for(auto rit = elems.rbegin(); rit != elems.rend(); ++rit) {
            append((*rit).first, (*rit).second);
        }
    }
    ~Polynomial() {
        cleanup(head);
    }

    void cleanup(ListNode* node) {
        if(node == nullptr) return;
        cleanup(node->next);
        delete node;
    }

    void print() const {
        for(ListNode* ptr = head; ptr != nullptr; ptr = ptr->next) {
            if(ptr == head && ptr->ci < 0) printf("- ");
            printf("%.1f", std::abs(ptr->ci));
            if(ptr->i > 1) printf("x^%d", ptr->i);
            if(ptr->i == 1) printf("x");
            if(ptr->next != nullptr) printf(ptr->next->ci < 0 ? " - " : " + ");
        }
        printf("\n");
    }

    [[nodiscard]] std::string ppr() const {
        std::stringstream ss;
        ss << "{";
        for(ListNode* ptr = head; ptr != nullptr; ptr = ptr->next) {
            ss << "{" << ptr->i << ", " << ptr->ci << "}";
            if(ptr->next != nullptr) ss << ", ";
        }
        ss << "}";
        return ss.str();
    }


    [[nodiscard]] std::string pprr() const {
        if(head == nullptr) return "{}";
        std::stringstream ss;
        ss << "{" << head->ppr() << "}";
        return ss.str();
    }

    float evaluate(float x);

    bool equalTo(Polynomial& other);

private:
    void append(int i, float ci) {
        if(head == nullptr) {
            head = new ListNode(i, ci);
            return;
        }

        ListNode* ptr = head;
        while(ptr->next != nullptr) ptr = ptr->next;
        ptr->next = new ListNode(i, ci);
    }
};


struct Node {
    int data;
    Node *next;

    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class CyclicLinkedList {

public:
    Node *start;

    // Erzeugt eine CyclicLinkedList mit 'count' Knoten
    // Die Nummerierung der Knoten fängt mit 1 an
    explicit CyclicLinkedList(int count) {
        start = new Node(1);
        Node *n = start;
        for (int i = 2; i <= count; ++i) {
            Node *m = new Node(i);
            n->next = m;
            n = m;
        }
        n->next = start;
    }

    ~CyclicLinkedList() {
        if (start == nullptr)
            return;
        Node *h = start;
        do {
            Node *n = h;
            h = h->next;
            delete n;
        } while (h != start);
    }

    void print() {
        printf("CyclicLinkedList:");
        if (start == nullptr)
            return;
        Node *h = start;
        do {
            printf(" %d", h->data);
            h = h->next;
        } while (h != start);
        printf("\n");
    }
};

std::pair<vector<int>, int> josephus(int n, int k);

static void printList(vector<int>& numbers) {
    std::stringstream ss;
    std::string sep;
    for (int i: numbers) {
        ss << sep << i;
        sep = ", ";
    }
    printf("%s\n", ss.str().c_str());
}

#endif //PROGRAMMIERAUFGABEN_BLATT0_H
