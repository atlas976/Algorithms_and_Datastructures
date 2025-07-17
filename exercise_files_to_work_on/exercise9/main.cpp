#include "include/blatt9.h"

void aufgabe2() {
    Queue q;
    q.enqueue(3);
    q.enqueue(7);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(5);
    printQueue(q);

    q.dequeue();
    q.dequeue();
    printQueue(q);
}

void aufgabe3() {
    stack<int> st;
    st.push(3);
    st.push(7);
    st.push(1);
    st.push(2);
    st.push(5);

    printf("Before sort: ");
    printStack(st);
    stackSort(st);

    printf("After sort:  ");
    printStack(st);
}


int main() {
    aufgabe2();
//    aufgabe3();
}
