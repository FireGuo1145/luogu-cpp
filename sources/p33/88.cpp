// P3388 【模板】割点（割顶）
// https://www.luogu.com.cn/problem/P3388

#include<bits/stdc++.h>

std::vector<int> dfn, low, cut;
std::vector<std::vector<int>> g;
int n, m, cnt, ans;
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++cnt;
    int child = 0;
    for(int v : g[u]) {
        if(!dfn[v]) {
            child++;
            tarjan(v, u);
            low[u] = std::min(low[u], low[v]);
            if(fa != 0 && low[v] >= dfn[u]) cut[u] = true;
        } else if(v != fa) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if(fa == 0 && child > 1) cut[u] = true;
}
int main() {
    std::cin >> n >> m;
    g.resize(n + 1);
    dfn.resize(n + 1);
    low.resize(n + 1);
    cut.resize(n + 1);
    for(int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) tarjan(i, 0);
    }
    for(int i = 1; i <= n; i++) {
        if(cut[i]) ans++;
    }
    std::cout << ans << std::endl;
    for(int i = 1; i <= n; i++) {
        if(cut[i]) std::cout << i << ' ';
    }
    std::cout << std::endl;
    return 0;
}