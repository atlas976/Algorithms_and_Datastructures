#include "../include/blatt9.h"


//exercise2
void Queue::enqueue(int x) {
    stack1.push(x);
}
    

int Queue::dequeue() {
    //check if queue is empty
    if (stack1.empty()) {
        return false;
    }

    //copy stack with reversed order
    while (!stack1.empty()) {
        stack2.push(stack1.top());
        stack1.pop();
    }

    //pop the firstOut in the queue
    int toPop = stack2.top();
    stack2.pop();

    //restore the order in stack 1
    while (!stack2.empty()) {
        stack1.push(stack2.top());
        stack2.pop();
    }
    
    //return the firstOut element in the queue
    return toPop;
}


bool Queue::isEmpty() {
    if (stack1.empty()) {
        return true;
    }
    else {
        return false;
    }
}



// exercise3
void sortedInsert(stack<int>& st, int val) {
    //chack if either the stack is empty or if u can insert
    //directly on the rest of the stack
    if (st.empty() || val < st.top()) {
        st.push(val);
        return;
    }
    //remember elements and go rec through the stack
    int temp = st.top();
    st.pop();
    //rec cakk
    sortedInsert(st, val);
    //insert the remembered elements which are already sorted
    st.push(temp);
}

void stackSort(stack<int>& st) {
    //base case
    if (st.empty()) {
        return;
    }
    // go so long through the stack until all elements are remember
    // and then start to insert them in sorted order
    int toInsert = st.top();
    st.pop();
    //rec call
    stackSort(st);
    //after working throgh the stack start inserting
    sortedInsert(st, toInsert);
}



/**
 *  ========== Helperfunctions ==========
 *
 *  void printStack(stack<int>& st)
 *  -> prints the elements of the stack
 *
 *  void printQueue(Queue& q)
 *  -> prints the elements of the queue
 *
 */