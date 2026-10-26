// P4281 [AHOI2008] 紧急集合 / 聚会
// https://www.luogu.com.cn/problem/P4281

#include<bits/stdc++.h>

const int LOG = 20;

std::vector<std::vector<int>> graph;
std::vector<std::vector<int>> ancestor;
std::vector<int> depth;

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

int query(int u, int v) {// 查询共同祖先
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

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    graph.resize(n + 1);
    ancestor.assign(n + 1, std::vector<int>(LOG, 0));
    depth.assign(n + 1, 0);
    for (int i = 1; i < n; i++) {
        int u, v;
        std::cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    build(1);
    while (m--) {
        int x, y, z;
        std::cin >> x >> y >> z;
        int a = query(x, y);
        int b = query(x, z);
        int c = query(y, z);int meet = a;
        if (depth[b] > depth[meet]) meet = b;
        if (depth[c] > depth[meet]) meet = c;
        int cost = depth[x] + depth[y] + depth[z] - depth[a] - depth[b] - depth[c];
        std::cout << meet << " " << cost << std::endl;
    }
    return 0;
}