// U744922 萌新赛模拟赛T3
// https://www.luogu.com.cn/problem/U744922

#include<bits/stdc++.h>
struct Edge {
    int u, v;
    long long w;
};
std::vector<int> fa;

int find(int x) {
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

bool merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    fa[x] = y;
    return true;
}

bool compare(Edge a, Edge b) {
    return a.w < b.w;
}

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<Edge> edges;
    std::vector<int> t(k + 1), w(k + 1);
    for (int i = 1; i <= k; i++) {
        std::cin >> t[i] >> w[i];
        int first;
        std::cin >> first;
        for (int j = 2; j <= t[i]; j++) {
            int v;
            std::cin >> v;
            edges.push_back({first, v, w[i]});
        }
    }
    for (int i = 1; i <= m; i++) {
        int u, v, c;
        std::cin >> u >> v >> c;
        // edges[u].push_back({v, c});
        edges.push_back({u, v, c});
    }
    std::sort(edges.begin(), edges.end(), compare); // 费用低的先配
    fa.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    long long ans = 0;
    int cnt = 0;
    for (auto e : edges) {
        if (merge(e.u, e.v)) {  // 先配带动后配（
            ans += e.w;
            cnt++;
        }
    }
    if (cnt == n - 1) std::cout << ans << std::endl;
    else std::cout << -1 << std::endl;
    return 0;
}