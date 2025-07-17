#include <stack>
#include <sstream>

#ifndef PROGRAMMIERAUFGABEN_BLATT0_H
#define PROGRAMMIERAUFGABEN_BLATT0_H


using std::stack;

class Queue {
    stack<int> stack1, stack2;

public:
    void enqueue(int x);

    int dequeue();

    bool isEmpty();
};

void stackSort(stack<int>& st);

static std::string stackString(stack<int> st) {
    std::stringstream ss;
    std::string del = "<-> ";
    while(!st.empty()) {
        int elem = st.top();
        ss << del << elem;
        del = ", ";
        st.pop();
    }
    ss << " |";
    return ss.str();
}

static void printStack(stack<int>& st) {
    printf("%s\n", stackString(st).c_str());
}

static void printQueue(Queue& q) {
    printf("<- ");
    while(!q.isEmpty()) {
        printf("%d ", q.dequeue());
    }
    printf(" <-\n");
}
#endif //PROGRAMMIERAUFGABEN_BLATT0_H
