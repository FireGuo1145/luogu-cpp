// P14823 [ICPC 2023 Yokohama R] Do It Yourself?
// https://luogu.com.cn/problem/P14823

#include<bits/stdc++.h>

const int LOG = 20;

std::vector<std::vector<int>> graph;
std::vector<long long> f;
std::vector<int> hvy;
std::vector<int> siz;
std::vector<int> dfn;
std::vector<int> mp;
std::vector<long long> m;
std::priority_queue<std::pair<long long, int>> pq;
int timer = 0;

long long add(int u) {
    return 1LL * f[u] * (2 * m[u] + 1);
}
long long sub(int u) {
    return 1LL * f[u] * (2 * m[u] - 1);
}
void dfs1(int u) {
    siz[u] = 1;
    for (int v : graph[u]) {
        dfs1(v);
        siz[u] += siz[v];
        if (siz[v] > siz[hvy[u]]) {
            hvy[u] = v;
        }
    }
}

void dfs2(int u) {  // 构建子树连续的遍历顺序
    dfn[u] = ++timer;
    mp[timer] = u;
    if (hvy[u]) dfs2(hvy[u]);
    for (int v : graph[u]) {
        if (v == hvy[u]) continue;
        dfs2(v);
    }
}

void dfs3(int u, bool keep) {
    if (hvy[u] == 0) {
        if (keep) pq.push({sub(u), u});
        return;
    }
    for (int v : graph[u]) {
        if (v == hvy[u]) continue;
        dfs3(v, false);
    }
    if (hvy[u]) dfs3(hvy[u], true);
    for (int i = dfn[hvy[u]] + siz[hvy[u]]; i < dfn[u] + siz[u]; i++) {
        int v = mp[i];
        if (m[v] > 0) pq.push({sub(v), v});
    }
    while (!pq.empty()) {
        auto [w, v] = pq.top();
        if (w <= add(u)) break;
        pq.pop();
        m[u]++;
        m[v]--;
        if (m[v] > 0) pq.push({sub(v), v});
    }
    if (keep) {
        if (m[u] > 0) pq.push({sub(u), u});
    } else {
        std::priority_queue<std::pair<long long, int>>().swap(pq);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    graph.resize(n + 1);
    mp.resize(n + 1, 0);
    dfn.resize(n + 1, 0);
    hvy.resize(n + 1, 0);
    siz.resize(n + 1, 0);
    f.resize(n + 1, 0);
    m.assign(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        int u;
        std::cin >> u;
        graph[u].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        std::cin >> f[i];
    }
    dfs1(1);
    dfs2(1);
    dfs3(1, false);
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += f[i] * m[i] * m[i];
    }
    std::cout << ans << std::endl;
    return 0;
}