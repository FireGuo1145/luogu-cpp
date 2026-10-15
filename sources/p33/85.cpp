// P3385 【模板】负环
// https://www.luogu.com.cn/problem/P3385

#include<bits/stdc++.h>

int main() {
    int T;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int m, n;
        std::cin >> n >> m;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
        std::vector<int> distant(n + 1, INT_MAX);
        distant[1] = 0;
        q.push({0, 1});
        std::vector<std::vector<std::pair<int, int>>> edges(n + 1, std::vector<std::pair<int, int>>());
        for (int j = 0; j < m; j++) {
            int u, v, w;
            std::cin >> u >> v >> w;
            if (w >= 0) {
                edges[u].push_back({v, w});
                edges[v].push_back({u, w});
            } else {
                edges[u].push_back({v, w});
            }
        }
        bool havenegacycle = false;
        for (int i = 1; i <= n; i++) {
            bool modified = false;
            for (int j = 1; j <= n; j++) {
                for (auto [v, w] : edges[j]) {
                    if (distant[j] == INT_MAX) continue;
                    if (distant[j] + w < distant[v]) {
                        distant[v] = distant[j] + w;
                        q.push({distant[v], v});
                        modified = true;
                    }
                }
            }
            if (!modified) break;
            if (i == n) havenegacycle = true;
        }
        std::cout << (havenegacycle ? "YES" : "NO") << std::endl;
    }
    return 0;
}