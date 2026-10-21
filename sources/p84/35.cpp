// P8435 【模板】点双连通分量
// https://www.luogu.com.cn/problem/P8435

#include<bits/stdc++.h>

std::vector<std::vector<std::pair<int,int>>> g; // 邻接表
std::vector<int> dfn, low, bridge, id;  // dfn: 时间戳 low: 能到达的最小时间戳  bridge: 是否为桥 id: 所在的连通分量
std::vector<std::vector<int>> ans;  // 存储每个连通分量
std::stack <int> stk;
int n, m, timer, cnt;   // n: 点数 m: 边数 timer: 时间戳 cnt: 连通分量个数

void tarjan(int u, int parentEdge) {
    stk.push(u);
    dfn[u] = low[u] = ++timer;
    for(auto [v, edgeId] : g[u]) {  // 每条边的到哪以及边的id，边的id是按照输入顺序的
        if(edgeId == parentEdge) continue;  // 父子免得套娃
        if(!dfn[v]) {
            tarjan(v, edgeId);  // 递归
            low[u] = std::min(low[u], low[v]);
            if(low[v] >= dfn[u]) {
                std::vector<int> c;
                while (true) {
                    int x = stk.top();
                    stk.pop();
                    c.push_back(x);
                    if(x == v) break;
                }
                c.push_back(u);
                ans.push_back(c);
            }
        } else if(dfn[v] < dfn[u]) {
            low[u] = std::min(low[u], dfn[v]);  // 被用过了（悲）
        }
    }
    if (parentEdge == -1) {
        if (g[u].empty()) {
            ans.push_back({u});
        }
        stk.pop();
    }
}

int main() {
    std::cin >> n >> m;
    g.resize(n + 1);
    dfn.resize(n + 1);
    low.resize(n + 1);
    bridge.resize(m);
    id.resize(n + 1);
    for(int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        if (u == v) continue;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) tarjan(i, -1);
    }
    std::cout << ans.size() << std::endl;
    for(auto &c : ans) {
        std::cout << c.size() << " ";
        for(int u : c) {
            std::cout << u << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}