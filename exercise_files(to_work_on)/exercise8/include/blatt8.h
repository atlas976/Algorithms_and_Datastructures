#include <sstream>
#include <cmath>
#include <vector>

#ifndef PROGRAMMIERAUFGABEN_BLATT0_H
#define PROGRAMMIERAUFGABEN_BLATT0_H

using std::vector;

int max_subarray(vector<int>& a);

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

    void flip();

    void moveUp(float c);

    void add(Polynomial& other);

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
