#include <gtest/gtest.h>
#include <random>
#include <queue>
#include "../include/blatt9.h"

typedef std::mt19937 MyRNG;
uint32_t seed_val = 75823946;
MyRNG rng;

unsigned int randomInt(int min, int max) {
    std::uniform_int_distribution<uint32_t> dist(min, max);
    return dist(rng);
}

void simulateEnqueue(Queue& q, std::queue<int>& sol, std::stringstream& ss){
    int elem = randomInt(0, 10000);
    q.enqueue(elem);
    sol.push(elem);
    ss << "Enq(" << elem << "), ";
}

bool simulateDequeue(Queue& q, std::queue<int>& sol, std::stringstream& ss) {
    int impl = q.dequeue();
    int res = sol.front();
    sol.pop();
    ss << "Deq(), ";
    if(impl != res) {
        ss << "\n" << "Dequeue failed: Expected " << res << ", but got " << impl;
    }
    return impl == res;
}

TEST(QueueTest, RandomOperations) {
    rng.seed(seed_val);

    for(int i = 0; i < 200; i++) {
        Queue q;
        std::queue<int> sol;
        unsigned int n = randomInt(5, 40);
        std::stringstream ss;

        while(n) {
            if(q.isEmpty() != sol.empty()) {
                FAIL() << "IsEmpty gives wrong response. Expected " << sol.empty() << ", but got " << q.isEmpty() << "\nOperations:  " << ss.str();
            }
            if(q.isEmpty()) {
                simulateEnqueue(q, sol, ss);
            } else {
                int op = randomInt(0, 10);
                if(op > 3)
                    simulateEnqueue(q, sol, ss);
                else {
                    bool output = simulateDequeue(q, sol, ss);
                    ASSERT_TRUE(output) << "\nOperations:  " << ss.str();
                }
            }

            n--;
        }
    }
}


TEST(StackSortTest, RandomStacks) {
    rng.seed(seed_val);

    for(int i = 0; i < 200; i++) {
        stack<int> st;
        unsigned int n = randomInt(5, 40);
        std::stringstream ss;

        while (n) {
            int elem = randomInt(0, 10000);
            st.push(elem);
            n--;
        }

        std::string unsorted = stackString(st);
        stackSort(st);
        std::string sorted = stackString(st);

        int elem = st.top();
        st.pop();
        while (!st.empty()) {
            if (elem > st.top()) {
                FAIL() << "Stack not properly sorted!\nBefore sort:\t" << unsorted << "\nAfter sort: \t" << sorted;
            }
            st.pop();
        }
    }
}