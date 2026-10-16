// P1144 最短路计数
// https://www.luogu.com.cn/problem/P1144

#include<bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> edges(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    std::vector<int> dist(n + 1, -1), count(n + 1, 0);
    std::queue<int> q;
    dist[1] = 0;
    count[1] = 1;
    q.push(1);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : edges[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                count[v] = count[u];
                q.push(v);
            } else if (dist[v] == dist[u] + 1) {
                count[v] = (count[u] + count[v]) % 100003;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        std::cout << count[i] << std::endl;
    }
    return 0;
}