// P1892 [BalticOI 2003] 团伙 (Day 2)
// https://www.luogu.com.cn/problem/P1892

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
    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) sets[i] = i;
    std::vector<std::vector<int>> enermies(n + 1, std::vector<int>());
    for (int i = 1; i <= m; i++) {
        char opt;
        int p, q;
        std::cin >> opt >> p >> q;
        if (opt == 'F') merge(p, q);
        else {
            enermies[p].push_back(q);
            enermies[q].push_back(p);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < enermies[i].size(); j++) {
            if (j != 0) merge(enermies[i][j], enermies[i][0]);
        }
    }
    int count = 0;
    for (int i = 1; i <= n; i++) if (find(i) == i) count++;
    std::cout << count << std::endl;
    return 0;
}