// @Title: P3384 【模板】重链剖分 / 树链剖分
// @Link: https://www.luogu.com.cn/problem/P3384
// @Author: FireGuo
// @Time: 2026-11-16 10:55

#include <bits/stdc++.h>

// 重点逻辑：向上找 lca 然后看路程的时候，通过先跳到该链的顶端然后跳到父节点就能到上一条链，再继续循环向上跳就能算到路程
// 每个点到深度更低的点都能通过几个链的变化来实现

int n, m, r, MOD;
std::vector<long long> a;
std::vector<std::vector<int>> adj;
std::vector<int> fa;// 父节点
std::vector<int> dep;// 深度
std::vector<int> sz;// 子树大小
std::vector<int> son;// 重儿子
std::vector<int> top;// 该链的顶端
std::vector<int> dfn;// DFS 序
std::vector<int> rnk;// DFS 序的反向映射
std::vector<long long> weight;// 节点权值
int cnt = 0;// 数第几个链

std::vector<long long> tree;// 线段树
std::vector<long long> lazy;// 懒标记

// 第一次 DFS，建立父子节点的映射关系
void dfs1(int u, int f, int d) {
    fa[u] = f;
    dep[u] = d;
    sz[u] = 1;
    int max_sz = -1;
    
    for (int v : adj[u]) {
        if (v == f) continue;
        dfs1(v, u, d + 1);
        sz[u] += sz[v];
        if (sz[v] > max_sz) {
            max_sz = sz[v];
            son[u] = v;
        }
    }
}

// 第二次 DFS，拆成几个链，建立 DFS 序
void dfs2(int u, int t) {
    top[u] = t;
    dfn[u] = ++cnt;
    rnk[cnt] = u;
    weight[cnt] = a[u];
    
    if (!son[u]) return;
    
    dfs2(son[u], t);
    
    for (int v : adj[u]) {
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

void push_up(int node) {
    tree[node] = (tree[node * 2] + tree[node * 2 + 1]) % MOD;
}

void push_down(int node, int l, int r) {
    if (lazy[node]) {
        int mid = (l + r) / 2;
        lazy[node * 2] = (lazy[node * 2] + lazy[node]) % MOD;
        tree[node * 2] = (tree[node * 2] + lazy[node] * (mid - l + 1)) % MOD;
        lazy[node * 2 + 1] = (lazy[node * 2 + 1] + lazy[node]) % MOD;
        tree[node * 2 + 1] = (tree[node * 2 + 1] + lazy[node] * (r - mid)) % MOD;
        lazy[node] = 0;
    }
}

void build(int node, int l, int r) {
    if (l == r) {
        tree[node] = weight[l] % MOD;
        return;
    }
    int mid = (l + r) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    push_up(node);
}

void update_range(int node, int l, int r, int ql, int qr, long long val) {
    if (ql <= l && r <= qr) {
        lazy[node] = (lazy[node] + val) % MOD;
        tree[node] = (tree[node] + val * (r - l + 1)) % MOD;
        return;
    }
    push_down(node, l, r);
    int mid = (l + r) / 2;
    if (ql <= mid) update_range(node * 2, l, mid, ql, qr, val);
    if (qr > mid) update_range(node * 2 + 1, mid + 1, r, ql, qr, val);
    push_up(node);
}

long long query_range(int node, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr) {
        return tree[node] % MOD;
    }
    push_down(node, l, r);
    int mid = (l + r) / 2;
    long long res = 0;
    if (ql <= mid) res = (res + query_range(node * 2, l, mid, ql, qr)) % MOD;
    if (qr > mid) res = (res + query_range(node * 2 + 1, mid + 1, r, ql, qr)) % MOD;
    return res;
}

long long query_path(int x, int y) {
    long long ans = 0;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
        ans = (ans + query_range(1, 1, n, dfn[top[x]], dfn[x])) % MOD;
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) std::swap(x, y);
    ans = (ans + query_range(1, 1, n, dfn[x], dfn[y])) % MOD;
    return ans;
}

void update_path(int x, int y, long long val) {
    val %= MOD;
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
        update_range(1, 1, n, dfn[top[x]], dfn[x], val);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y]) std::swap(x, y);
    update_range(1, 1, n, dfn[x], dfn[y], val);
}

long long query_subtree(int x) {
    return query_range(1, 1, n, dfn[x], dfn[x] + sz[x] - 1);
}

void update_subtree(int x, long long val) {
    update_range(1, 1, n, dfn[x], dfn[x] + sz[x] - 1, val);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> r >> MOD;
    a.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    fa.resize(n + 1, 0);
    dep.resize(n + 1, 0);
    sz.resize(n + 1, 0);
    son.resize(n + 1, 0);
    top.resize(n + 1, 0);
    dfn.resize(n + 1, 0);
    rnk.resize(n + 1, 0);
    weight.resize(n + 1, 0);
    dfs1(r, 0, 1);
    dfs2(r, r);
    tree.resize(4 * n + 5, 0);
    lazy.resize(4 * n + 5, 0);
    build(1, 1, n);
    while (m--) {
        int op, x, y;
        long long z;
        std::cin >> op;
        if (op == 1) {
            std::cin >> x >> y >> z;
            update_path(x, y, z);
        } else if (op == 2) {
            std::cin >> x >> y;
            std::cout << query_path(x, y) << std::endl;
        } else if (op == 3) {
            std::cin >> x >> z;
            update_subtree(x, z);
        } else if (op == 4) {
            std::cin >> x;
            std::cout << query_subtree(x) << std::endl;
        }
    }
    return 0;
}