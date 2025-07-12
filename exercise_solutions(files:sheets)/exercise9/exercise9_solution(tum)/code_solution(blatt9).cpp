#include "../include/blatt9.h"

/// Aufgabe 2
void Queue::enqueue(int x) {
    stack1.push(x);
}

int Queue::dequeue() {
    if (stack2.empty())
        while(!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
    int elem = stack2.top();
    stack2.pop();
    return elem;
}

bool Queue::isEmpty() {
    return stack1.empty() && stack2.empty();
}

/// Aufgabe 3
void sortedInsert(stack<int>& st, int val) {
    // der einfache Fall, S ist leer
    if (st.empty()) {
        st.push(val);
        return;
    }
    // betrachten wir das obere Element
    int top = st.top();
    // falls es größer gleich val ist, dann ist der
    // richtige Platz für val ganz oben auf dem Stack
    if (top >= val)
        st.push(val);
        // sonst ist es irgendwo mitten im Stack
    else {
        // in diesem Fall können wir das obere Element entfernen
        st.pop();
        //  sortedInsert rekursiv aufrufen und
        sortedInsert(st, val);
        // top wieder auf den Stack oben legen
        // (nach dem Einfügen von val sollte top oben bleiben)
        st.push(top);
    }
}

void stackSort(stack<int>& st) {
    if (st.empty()) return;
    // wir entfernen das obere Element vom Stack
    int top = st.top();
    st.pop();
    // sortieren den restlichen Stack rekursiv
    stackSort(st);
    // und benutzen sortedInsert, um das zuvor entfernte
    // obere Element an die richtige Stelle in den sortierten
    // Stack einzufügen
    sortedInsert(st, top);
}

/**
 *  ========== Hilfsfunktionen ==========
 *
 *  void printStack(stack<int>& st)
 *  -> Gibt die Elemente des Stack aus
 *
 *  void printQueue(Queue& q)
 *  -> Gibt die Elemente der Queue aus
 *
 */