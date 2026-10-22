// P1262 [POI 1996 R3] 间谍网络
// https://www.luogu.com.cn/problem/P1262

#include<bits/stdc++.h>

std::vector<int> dfn, low, instack, id, orin;
std::vector<std::vector<int>> g, dag;
std::stack<int> s;
int n, p, cnt, scc;
void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    s.push(u);
    instack[u] = true;
    for (int v : g[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        } else if (instack[v]) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        int v;
        ++scc;
        while (true) {
            v = s.top();
            s.pop();
            instack[v] = false;
            id[v] = scc;
            dag[scc].push_back(v);
            ++orin[scc];
            if (v == u) break;
        }
    }
}
int main() {
    std::cin >> n >> p;
    g.resize(n + 1);
    dfn.resize(n + 1);
    std::vector<int> prices(n + 1, -1);
    dag.resize(n + 1);
    low.resize(n + 1);
    instack.resize(n + 1);
    id.resize(n + 1);
    orin.resize(n + 1);
    for (int i = 1; i <= p; i++) {
        int u, price;
        std::cin >> u >> price;
        prices[u] = price;
    }
    int r;
    std::cin >> r;
    for (int i = 1; i <= r; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    std::vector<bool> vis(n + 1, false);
    std::stack<int> st;
    for (int i = 1; i <= n; i++) {
        if (prices[i] != -1) {
            st.push(i);
            vis[i] = true;
        }
    }
    while (!st.empty()) {
        int u = st.top();
        st.pop();
        for (int v : g[u]) {
            if (!vis[v]) {
                vis[v] = true;
                st.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            std::cout << "NO\n" << i;
            return 0;
        }
    }
    std::vector<int> mn(scc + 1, -1), indeg(scc + 1, 0);
    for (int i = 1; i <= n; i++) {
        int c = id[i];
        if (prices[i] != -1 && (mn[c] == -1 || prices[i] < mn[c])) mn[c] = prices[i];
    }
    for (int u = 1; u <= n; u++) {
        for (int v : g[u]) {
            if (id[u] != id[v]) indeg[id[v]]++;
        }
    }
    int ans = 0;
    for (int i = 1; i <= scc; i++) {
        if (indeg[i] == 0) ans += mn[i];
    }
    std::cout << "YES\n" << ans;
    return 0;
}