/*
 * Knuth-Morris-Pratt (KMP) Algorithm for Substring Search
 * O(N + M)
 *
 * LPS: Longest Prefix Suffix Array
 * When there is a mismatch, instead of going back to the start, go back to the index in LPS and continue searching --> Linear time
 *
 * Returns the first index of string B found in string A
 * Problem: https://dmoj.ca/problem/bf4
 */

#include <bits/stdc++.h>
using namespace std;
vector<int> LPS;

void buildKMP (string s) {
    int L = LPS[0] = 0, i = 1;
    while(i < s.size()) {
        if(s[i] == s[L]) {
            LPS[i++] = ++L;
        }
        else {
            if(L != 0) {
                L = LPS[L-1];
            }
            else {
                LPS[i++] = 0;
            }
        }
    }
}

int KMPfindIdx (string s, string sub) {
    LPS = vector<int>(sub.size());
    buildKMP(sub);
    int i = 0, j = 0;
    while(i < s.size()) {
        if(sub[j] == s[i]) {
            i++;
            j++;
        }
        if(j == sub.size()) {
            return (i-j);
        }
        else if(sub[j] == s[i]) {
            if(j != 0) {
                j = LPS[j-1];
            }
            else {
                i++;
            }
        }
    }
    return -1;
}

string a, b;
int main () {
    cin >> a >> b;
    cout << KMPfindIdx(a, b) << "\n";
}
