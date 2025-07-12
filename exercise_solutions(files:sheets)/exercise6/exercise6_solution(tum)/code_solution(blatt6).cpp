#include "../include/blatt6.h"

/// Aufgabe 2

// Konstante, legt maximale Werte für n und k fest
const int N = 1000;

// Globales zweidimensionales Array, um die bereits
// berechneten Binomialkoeffizienten zu merken
long long lookup[N][N] = {0};

long long binom_memo(int n, int k) {
    // Falls binom(n, k) bereits berechnet wurde:
    if(lookup[n][k] != 0) {
        return lookup[n][k];
    }

    // Falls binom(n, k) noch nicht berechnet wurde:
    // berechne und merke den Wert
    if (k == 0 || k == n) { // nichtrekursiver Fall
        lookup[n][k] = 1;
    }
    else { // Rekursionsfall
        // Wichtig: hier müssen wir binom rekursiv
        // aufrufen, da wir nicht wissen, ob
        // lookup[n-1][k-1] und lookup[n-1][k]
        // schon berechnet wurden!
        lookup[n][k] = binom_memo(n-1, k-1) + binom_memo(n-1, k);
    }
    return lookup[n][k];
}


/// Aufgabe 3
void selection_sort_rec_it(vector_iterator from, vector_iterator to) {
    // Falls das Array weniger als zwei Elemente enthält, ist nichts zu tun
    if(to - from <= 1) return;

    //Finde das minimale Element
    auto min_i = from;
    for(auto it = from; it != to; ++it) {
        if(*it < *min_i) min_i = it;
    }

    // Vertausche das minimale Element mit dem ersten Element
    // Das minimale Element ist jetzt an der richtigen Stelle
    int tmp = *from;
    *from = *min_i;
    *min_i = tmp;

    // Fahre fort mit dem Rest des Arrays
    selection_sort_rec_it(from + 1, to);
}

void selection_sort_rec(vector<int>& vec, int from) {
    // Falls das Array weniger als zwei Elemente enthält, ist nichts zu tun
    if(vec.size() - from <= 1) return;

    //Finde das minimale Element
    int min_i = from;
    for(int i = from; i < vec.size(); ++i) {
        if(vec.at(i) < vec.at(min_i)) min_i = i;
    }

    // Vertausche das minimale Element mit dem ersten Element
    // Das minimale Element ist jetzt an der richtigen Stelle
    int tmp = vec.at(from);
    vec.at(from) = vec.at(min_i);
    vec.at(min_i) = tmp;

    // Fahre fort mit dem Rest des Arrays
    selection_sort_rec(vec, from + 1);
}

void selection_sort(vector<int>& vec) {
    selection_sort_rec_it(vec.begin(), vec.end());
//    selection_sort_rec(vec, 0);
}

/// Aufgabe 4a)

int search(vector<int>& vec, int c, int x, int l, int r) {
    // Nichts gefunden
    if (r - l < 0) return -1;

    int t = (r+l) / 2;
    // die "wirkliche" (verschobene) Position des mittleren Elements
    int mt = (t + c) % vec.size();
    if (vec[mt] == x) return mt;

    if (vec[mt] < x)
        return search(vec, c, x, t+1, r);
    else
        return search(vec, c, x, l, t-1);
}

int search(vector<int>& vec, int c, int x) {
    if(vec.size() <= 1) return 0;
    return search(vec, c, x, 0, vec.size()-1);
}

/// Aufgabe 4b)
int	get_shift_iter(vector<int>& vec) {
    if(vec.size() <= 1) return 0;

    // Initialisiere
    int l = 0;
    int r = vec.size()-1;
    // idx ist der Index des Minimums
    int idx = 0;

    while (l <= r) {
        // Betrachte das mittlere Element
        // Wenn es kleiner als das bisherige Minimum ist,
        // dann aktualisiere idx
        int t = (r+l) / 2;
        if (vec[t] < vec[idx])
            idx = t;

        // Falls a[r] > a[t] dann sind alle a[i] > a[t]
        // für t+1 <= i <= r also kann das Minimum
        // nur im Teilarray [a[l], ..., a[t]] sein.
        // Da wir a[t] schon geprüft haben,
        // reicht es in [a[l], ..., a[t-1]] zu suchen.
        if (vec[r] > vec[t])
            r = t - 1;
            // Sonst a[r] < a[t], dann sind alle a[i] > a[r]
            // für l <= i <= t also kann das Minimum nur
            // im Teilarray [a[t+1], ..., a[r]] sein
        else
            l = t + 1;
    }
    return idx;
}


int get_shift_rec_help(const std::vector<int>& vec, int l, int r) {
    // If the array segment is already sorted or only one element
    if (r <= l || vec[l] < vec[r]) return l;

    int t = l + (r - l) / 2;  // Middle point

    // Check which half contains the pivot (minimum element)
    if (vec[t] > vec[r]) {
        // Pivot must be in the right half
        return get_shift_rec_help(vec, t + 1, r);
    } else {
        // Pivot must be in the left half
        return get_shift_rec_help(vec, l, t);
    }
}

int get_shift_rec(vector<int>& vec) {
    return get_shift_rec_help(vec, 0, vec.size()-1);
}

int get_shift(vector<int>& vec) {
//    return get_shift_iter(vec);
    return get_shift_rec(vec);
}

/**
 *  ========== Hilfsfunktionen ==========
 *
 *  void printList(vector<int>& numbers)
 *  -> Gibt die Liste aus
 *
 */
