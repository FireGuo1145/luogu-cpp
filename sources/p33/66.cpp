// P3366 【模板】最小生成树
// https://www.luogu.com.cn/problem/P3366

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
    std::vector<std::tuple<long long, long long, long long>> edges;
    for (int i = 0; i < m; i++) {
        long long x, y, z;
        std::cin >> x >> y >> z;
        edges.push_back(std::make_tuple(z, x, y));
    }
    int ans = 0;
    std::sort(edges.begin(), edges.end(), [](auto a, auto b) { return std::get<0>(a) < std::get<0>(b); });
    for (auto [z, x, y] : edges) {
        if (find(x) != find(y)) {
            merge(x, y);
            ans += z;
        }
    }
    int tempparent = find(1);
    for (int i = 1; i <= n; i++) {
        if (find(i) != tempparent) {
            std::cout << "orz" << std::endl;
            return 0;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}