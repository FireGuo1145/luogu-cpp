// U744916 萌新赛模拟赛T2
// https://www.luogu.com.cn/problem/U744916

#include<bits/stdc++.h>

std::vector<int> sets;
std::vector<long long> s, power;

long long total = 0;

int find(int x) {
    if (sets[x] == x) return x;
    return sets[x] = find(sets[x]);
}
void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    total -= power[x] + power[y];
    power[y] += power[x] + s[x] * s[y];
    s[y] += s[x];
    sets[x] = y;
    total += power[y];
}
int main() {
    int n, m;
    std::cin >> n >> m;
    sets.resize(n + 1);
    s.resize(n + 1);
    power.resize(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> s[i];
        sets[i] = i;
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        // if (find(u) == find(v)) continue;
        merge(u, v);
        std::cout << total << std::endl;
    }
    return 0;
}