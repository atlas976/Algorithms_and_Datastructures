#include "../include/blatt3.h"

/**
 * Aufgabe 2
 */
int max_subarray(vector<int>& a) {
    if(a.empty())
        return 0;

    int best = a[0];
    // try left bound = l
    for (int l = 0; l < a.size(); ++l) {
        // try left bound = r
        for (int r = l; r < a.size(); ++r) {
            int v = 0;
            // sum all values from l to r
            for (int k = l; k <= r; ++k)
                v += a[k];

            // check if better than current best
            if (v > best) {
                best = v;
            }
        }
    }
    return best;
}

/**
 * Aufgabe 3b)
 */
int nextSeat(set<int>& room) {
    int bestDist = -1;
    int bestIndex = -1;
    int from = -1;

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

/**
 * Aufgabe 3c)
 */
vector<int> examRoomOrder(int n) {
    vector<int> order;
    set<int> room;

    room.insert(0);
    order.push_back(0);

    room.insert(n-1);
    order.push_back(n-1);

    for(int i = 2; i < n; i++) {
        int bestIndex = nextSeat(room);
        room.insert(bestIndex);
        order.push_back(bestIndex);
    }
    return order;
}


/**
 *  ========== Hilfsfunktionen ==========
 *
 *  void printList(vector<int>& numbers)
 *  -> Gibt die Liste aus
 *
 */