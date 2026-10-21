#include<bits/stdc++.h>

std::vector<std::vector<std::pair<int,int>>> g; // 邻接表
std::vector<int> dfn, low, bridge, id;  // dfn: 时间戳 low: 能到达的最小时间戳  bridge: 是否为桥 id: 所在的连通分量
std::vector<std::vector<int>> ans;  // 存储每个连通分量
int n, m, timer, cnt;   // n: 点数 m: 边数 timer: 时间戳 cnt: 连通分量个数

void tarjan(int u, int parentEdge) {
    dfn[u] = low[u] = ++timer;
    for(auto [v, edgeId] : g[u]) {  // 每条边的到哪以及边的id，边的id是按照输入顺序的
        if(edgeId == parentEdge) continue;  // 父子免得套娃
        if(!dfn[v]) {
            tarjan(v, edgeId);  // 递归
            low[u] = std::min(low[u], low[v]);
            if(low[v] > dfn[u]) bridge[edgeId] = true;  // 找桥，没法往回走就是桥
        } else {
            low[u] = std::min(low[u], dfn[v]);  // 被用过了（悲）
        }
    }
}
void dfs(int u, int c) {
    id[u] = c;
    ans[c].push_back(u);
    for(auto [v, edgeId] : g[u]) {
        if(bridge[edgeId] || id[v]) continue;
        dfs(v, c);
    }
}
int main() {
    std::cin >> n >> m;
    g.resize(n + 1);
    ans.resize(n + 1);
    dfn.resize(n + 1);
    low.resize(n + 1);
    bridge.resize(m);
    id.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) tarjan(i, -1);
    }
    for(int i = 1; i <= n; i++) {
        if(!id[i]) dfs(i, ++cnt);
    }
    std::cout << cnt << std::endl;
    for(int i = 1; i <= cnt; i++) {
        std::cout << ans[i].size() << " ";
        for(int u: ans[i]) std::cout << u << " ";
    }
    std::cout << std::endl;
    return 0;
}