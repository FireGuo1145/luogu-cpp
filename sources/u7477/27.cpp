// U747727 定时通道
// https://luogu.com.cn/problem/U747727

#include<bits/stdc++.h>

int main() {
    int n, m;

    std::cin >> n >> m;
    std::vector<std::vector<std::tuple<int, int, int, int>>> graph(n + 1);

    for(int i = 0; i < m; i++) {
        int u, v, w, p, r;
        std::cin >> u >> v >> w >> p >> r;
        graph[u].push_back({v, w, p, r});
    }
    std::vector<long long> dis(n + 1, LLONG_MAX);
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> q;
    dis[1] = 0;
    q.push({0, 1});
    while(!q.empty()) {
        auto [t, u] = q.top();
        q.pop();
        if(t != dis[u]) continue;
        for(auto [v, w, p, r] : graph[u]) {
            long long wait = (r - t % p + p) % p;
            long long nt = t + wait + w;
            if(nt < dis[v]) {
                dis[v] = nt;
                q.push({nt, v});
            }
        }
    }
    if(dis[n] == LLONG_MAX) std::cout << -1;
    else std::cout << dis[n];
    return 0;
}