/*
 * Difference Array for Range Update
 * O(1) update
 *
 * Stores the difference between adjacent elements --> updates the difference by said values
 * Converts back to regular array through prefix sum
 */

#include <bits/stdc++.h>
using namespace std;

const int MM = 1e5 + 5;
vector<int> arr, D;

void update (int L, int R, int x) {
    D[L] += x;
    D[R+1] -= x;
}

void buildDiff () {
    D = vector<int> (arr.size()+1);
    D[0] = arr[0];
    D[arr.size()] = 0;
    for(int i = 1; i < arr.size(); i++) {
        D[i] = arr[i] - arr[i-1];
    }
}

void convertBack () {
    for(int i = 0; i < arr.size(); i++) {
        if(i == 0) {
            arr[i] = D[i];
        }
        else {
            arr[i] = D[i] + arr[i-1];
        }
    }
}

int main () {}
