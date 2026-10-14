#include<bits/stdc++.h>

std::vector<int> sets(1000000);
int find(int x) {
    if (sets[x] == x) return x;
    else return sets[x] = find(sets[x]);
}

int main() {
    return 0;
}