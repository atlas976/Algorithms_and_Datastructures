#include "../include/blatt3.h"
#include <vector>
#include <climits>



//exercise 1
//brute force, so there is probably better O()
int max_subarray(std::vector<int>& a) {

    //initialise var
    int max_sum = INT_MIN;
    int n = a.size();

    //go through the single subarrays & calculate their sum
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int sum = 0;
            for (int k = i; k <= j; ++k) {
                sum += a[k];
            }
            if (sum > max_sum) {
                max_sum = sum;
            }
        }
    }

    //return the highest subarray
    if (a.size() == 0) {max_sum = 0;}
    return max_sum;
}



//exercise 2a
int nextSeat(set<int>& room) {

    //var
    int bestDist = -1;
    int bestIndex = -1;
    int from = -1;

    //calculate next seat
    for(int to: room) {
        if(from == -1) {
            from = to;
            continue;
        }

        int dist = (to - from) / 2;
        if(dist > bestDist) {
            bestDist = dist;
            bestIndex = from + dist;
        }
        from = to;
    }

    return bestIndex;
}



//exercise 2b
vector<int> examRoomOrder(int n) {

    vector<int> order;
    set<int> room;

    //first place
    room.insert(0);
    order.push_back(0);

    //second place
    room.insert(n-1);
    order.push_back(n-1);

    //calculate next...
    for(int i = 2; i < n; i++) {
        int bestIndex = nextSeat(room);
        room.insert(bestIndex);
        order.push_back(bestIndex);
    }
    return order;

}



/**
 *  ========== Helper Functions ==========
 *
 *  void printList(vector<int>& numbers)
 *  -> Prints the list
 *
 */



/**
 *  ========== Hilfsfunktionen ==========
 *
 *  void printList(vector<int>& numbers)
 *  -> Gibt die Liste aus
 *
 */