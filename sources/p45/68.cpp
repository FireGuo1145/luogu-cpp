// P4568 [JLOI2011] 飞行路线
// https://www.luogu.com.cn/problem/P4568

#include<bits/stdc++.h>

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    int s, t;
    std::cin >> s >> t;
    std::vector<std::vector<std::pair<int, int>>> edges(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        std::cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    std::vector<std::vector<long long>> dist(n, std::vector<long long>(k + 1, LLONG_MAX / 4));
    std::priority_queue<std::tuple<long long, int, int>, std::vector<std::tuple<long long, int, int>>, std::greater<>> pq;
    dist[s][0] = 0;
    pq.push({0, s, 0});
    while (!pq.empty()) {
        auto [distance, u, used] = pq.top();
        pq.pop();
        if (distance != dist[u][used]) continue;
        for (auto [v, w] : edges[u]) {
            if (dist[v][used] > distance + w) { //  一般性的有更便宜方法
                dist[v][used] = distance + w;   //  没用所以要加钱
                pq.push({dist[v][used], v, used});
            }
            if (used < k && dist[v][used + 1] > distance) { //  使用票的时候的更便宜方法
                dist[v][used + 1] = distance;   //  用了一张所以不加钱
                pq.push({dist[v][used + 1], v, used + 1});
            }
        }
    }
    long long ans = LLONG_MAX / 4;
    for (int i = 0; i <= k; ++i) {
        ans = std::min(ans, dist[t][i]);
    }
    std::cout << ans << std::endl;
    return 0;
}