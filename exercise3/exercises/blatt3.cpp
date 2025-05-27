#include "../include/blatt3.h"

/**
 * Aufgabe 2
 */
#include <vector>
#include <climits>


//brute force, gibt bessere laufzeit sicherlich
int max_subarray(std::vector<int>& a) {

    //var deklarieren
    int max_sum = INT_MIN;  // Funktioniert auch bei negativen Werten
    int n = a.size();

    //subarrays durchlaufen
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

    //ausgabe des wertes des größten subarrays
    if (a.size() == 0) {max_sum = 0;}
    return max_sum;
}


int nextSeat(set<int>& room) {

    //var deklarieren
    int bestDist = -1;
    int bestIndex = -1;
    int from = -1;

    //nächsten sitzplatz berechnen
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

    //ausgabe
    return bestIndex;
}


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