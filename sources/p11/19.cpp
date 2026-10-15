// P1119 灾后重建
// https://www.luogu.com.cn/problem/P1119

#include<bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> t(n);
    for (int i = 0; i < n; i++) {
        std::cin >> t[i];
    }
    std::vector<std::vector<int>> dists(n, std::vector<int>(n, INT_MAX / 2));
    for (int i = 0; i < n; i++) {
        dists[i][i] = 0;
    }
    std::vector<std::vector<std::pair<int, int>>> roads(n + 1, std::vector<std::pair<int, int>>());
    for (int k = 0; k < m; k++) {
        int i, j, w;
        std::cin >> i >> j >> w;
        roads[i].push_back({j, w});
        roads[j].push_back({i, w});
        dists[i][j] = w;
        dists[j][i] = w;
    }
    int q;
    std::cin >> q;
    // std::vector<std::tuple<int, int, int>> questions(q);
    std::vector<int> order(n);
    for (int i = 0; i < n; i++) {
        order[i] = i;
    }
    std::sort(order.begin(), order.end(), [&](int a, int b) {
        return t[a] < t[b];
    });
    int current = 0;
    for (int k = 0; k < q; k++) {
        int x, y, t1;
        std::cin >> x >> y >> t1;
        // questions[k] = std::make_tuple(x, y, t);
        if (t1 < t[x] || t1 < t[y]) {
            std::cout << "-1" << std::endl;
        } else {
            while (current < n && t[order[current]] <= t1) {
                int u = order[current];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        dists[i][j] = std::min(dists[i][j], dists[i][u] + dists[u][j]);
                    }
                }
                current++;
            }
            if (dists[x][y] >= INT_MAX / 2) {
                std::cout << "-1" << std::endl;
            } else {
                std::cout << dists[x][y] << std::endl;
            }
        }
    }
    return 0;
}