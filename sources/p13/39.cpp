// P1339 [USACO09OCT] Heat Wave G
// https://www.luogu.com.cn/problem/P1339

#include<bits/stdc++.h>

int main() {
    int n, m, s, t;
    std::cin >> n >> m >> s >> t;
    std::vector<std::vector<std::pair<int, int>>> edges(n + 1, std::vector<std::pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    std::vector<int> dist(n + 1, INT_MAX);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (auto [v, w] : edges[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    std::cout << dist[t] << std::endl;
    return 0;
}