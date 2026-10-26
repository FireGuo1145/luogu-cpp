// P2680 [NOIP 2015 提高组] 运输计划
// https://www.luogu.com.cn/problem/P2680

#include<bits/stdc++.h>

const int LOG = 20;
std::vector<std::vector<std::pair<int, int>>> graph;
std::vector<std::vector<int>> ancestor;
std::vector<int> depth;
std::vector<int> edgeWeight;
std::vector<long long> dis;
std::vector<int> order;
std::vector<int> parent;
std::vector<std::pair<int, int>> togo;
std::vector<int> pathLca;
std::vector<long long> pathLen;
std::vector<int> diff;
long long distMax;

void build(int root) {
    std::queue<int> q;
    q.push(root);
    depth[root] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (auto [v, w] : graph[u]) {
            if (v == parent[u]) continue;
            parent[v] = u;
            ancestor[v][0] = u;
            depth[v] = depth[u] + 1;
            for (int j = 1; j < LOG; j++) {
                ancestor[v][j] = ancestor[ancestor[v][j - 1]][j - 1];
            }
            edgeWeight[v] = w;
            dis[v] = dis[u] + w;
            q.push(v);
        }
    }
}

int query(int u, int v) {
    if (depth[u] < depth[v]) {
        std::swap(u, v);
    }
    int difference = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++) {
        if ((difference & (1 << i)) != 0) {
            u = ancestor[u][i];
        }
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (ancestor[u][i] != ancestor[v][i]) {
            u = ancestor[u][i];
            v = ancestor[v][i];
        }
    }
    return ancestor[u][0];
}

long long dist(int u, int v) {
    return dis[u] + dis[v] - 2 * dis[query(u, v)];
}

bool check(long long maxlen) {
    std::fill(diff.begin(), diff.end(), 0);
    int n = (int)order.size();
    int cnt = 0;
    for (int i = 0; i < (int)togo.size(); i++) {
        if (pathLen[i] > maxlen) {
            int u = togo[i].first;
            int v = togo[i].second;
            int lca = pathLca[i];
            diff[u]++;
            diff[v]++;
            diff[lca] -= 2;
            cnt++;
        }
    }
    if (cnt == 0) return true;
    long long maxEdge = 0;
    for (int i = (int)order.size() - 1; i >= 0; i--) {
        int u = order[i];
        if (u == 1) continue;
        if (diff[u] == cnt) {
            maxEdge = std::max(maxEdge, (long long)edgeWeight[u]);
        }
        diff[parent[u]] += diff[u];
    }
    return maxEdge > 0 && distMax - maxEdge <= maxlen;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    graph.resize(n + 1);
    diff.resize(n + 1);
    ancestor.assign(n + 1, std::vector<int>(LOG, 0));
    depth.assign(n + 1, 0);
    edgeWeight.assign(n + 1, 0);
    dis.assign(n + 1, 0);
    parent.assign(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    build(1);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        int p = query(u, v);
        long long len = dis[u] + dis[v] - 2LL * dis[p];
        togo.push_back({u, v});
        pathLca.push_back(p);
        pathLen.push_back(len);
        distMax = std::max(distMax, len);
    }
    long long l = 0, r = distMax;
    while (l < r) {
        long long mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    std::cout << l << std::endl;
    return 0;
}