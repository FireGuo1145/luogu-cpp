#include<bits/stdc++.h>

std::map<long long, long long> sets;
long long find(long long x) {
    if (sets.find(x) == sets.end()) sets[x] = x;
    if (sets[x] == x) return x;
    return sets[x] = find(sets[x]);
}

void merge(long long x, long long y) {
    sets[find(x)] = find(y);
}

int main() {
    return 0;
}