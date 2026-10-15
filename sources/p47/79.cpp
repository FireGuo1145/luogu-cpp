// P4779 【模板】单源最短路径（标准版）
// https://www.luogu.com.cn/problem/P4779

#include<bits/stdc++.h>

int main() {
    int n, m, s;
    std::cin >> n >> m >> s;
    std::vector<std::vector<std::pair<int, int>>> edges(n + 1);
    std::vector<int> dis(n + 1, INT_MAX);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
    dis[s] = 0;
    q.push({0, s});
    while (!q.empty()) {
        auto current = q.top();
        q.pop();
        int d = current.first;
        int u = current.second;
        if (d != dis[u]) {
            continue;
        }
        for (auto &edge : edges[u]) {
            int v = edge.first;
            int w = edge.second;
            if (dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                q.push({dis[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        std::cout << dis[i] << " ";
    }
    return 0;
}