// P3258 [JLOI2014] 松鼠的新家
// https://www.luogu.com.cn/problem/P3258

#include<bits/stdc++.h>

const int LOG = 20;

std::vector<std::vector<int>> graph;
std::vector<std::vector<int>> ancestor;
std::vector<int> depth;
std::vector<int> d;

void build(int root) {
    std::queue<int> q;
    q.push(root);
    depth[root] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int i = 0; i < (int)graph[u].size(); i++) {
            int v = graph[u][i];
            if (v == ancestor[u][0]) continue;

            ancestor[v][0] = u;
            depth[v] = depth[u] + 1;
            for (int j = 1; j < LOG; j++) {
                ancestor[v][j] = ancestor[ancestor[v][j - 1]][j - 1];
            }
            q.push(v);
        }
    }
}

int query(int u, int v) {
    if (depth[u] < depth[v]) {
        int temp = u;
        u = v;
        v = temp;
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

int dist(int u, int v) {
    return depth[u] + depth[v] - 2 * depth[query(u, v)];
}

void dfs(int u, int fa) {
    for (int v : graph[u]) {
        if (v == fa) continue;
        dfs(v, u);
        d[u] += d[v];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    graph.resize(n + 1);
    d.resize(n + 1, 0);
    ancestor.assign(n + 1, std::vector<int>(LOG, 0));
    depth.assign(n + 1, 0);
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    build(1);
    for (int i = 1; i < n; i++) {
        int u = a[i], v = a[i + 1];
        int l = query(u, v);
        d[u]++;
        d[v]++;
        d[l]--;
        d[ancestor[l][0]]--;
    }
    dfs(1, 0);
    for (int i = 2; i <= n; i++) {
        d[a[i]]--;
    }
    for (int i = 1; i <= n; i++) {
        std::cout << d[i];
        if (i != n) std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}