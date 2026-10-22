// P2515 [HAOI2010] 软件安装
// https://www.luogu.com.cn/problem/P2515



#include<bits/stdc++.h>

std::vector<int> dfn, low, instack, id, space, value, sumspace, sumvalue;
std::vector<std::vector<int>> g, dag, dp;
std::stack<int> s;
int n, m, cnt, scc;

void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    s.push(u);
    instack[u] = true;
    for(int v : g[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = std::min(low[u], low[v]);
        } else if(instack[v]) {
            low[u] = std::min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]) {
        ++scc;
        while(true) {
            int v = s.top();
            s.pop();
            instack[v] = false;
            id[v] = scc;
            sumspace[scc] += space[v];
            sumvalue[scc] += value[v];
            if(v == u) break;
        }
    }
}
void dfs(int u) {
    for(int j = sumspace[u]; j <= m; j++) dp[u][j] = sumvalue[u];
    for(int v : dag[u]) {
        dfs(v);
        for(int j = m; j >= sumspace[u]; j--) {
            for(int k = sumspace[v]; k <= j - sumspace[u]; k++) {
                if(dp[u][j-k] != -1 && dp[v][k] != -1) {
                    dp[u][j] = std::max(dp[u][j], dp[u][j-k] + dp[v][k]);
                }
            }
        }
    }
}
int main() {
    std::cin >> n >> m;
    g.resize(n + 1);
    dfn.resize(n + 1);
    low.resize(n + 1);
    instack.resize(n + 1);
    id.resize(n + 1);
    space.resize(n + 1);
    value.resize(n + 1);
    sumspace.resize(n + 1);
    sumvalue.resize(n + 1);
    for(int i = 1; i <= n; i++) std::cin >> space[i];
    for(int i = 1; i <= n; i++) std::cin >> value[i];
    for(int i = 1; i <= n; i++) {
        int d;
        std::cin >> d;
        g[d].push_back(i);
    }
    for(int i = 0; i <= n; i++) {
        if(!dfn[i]) tarjan(i);
    }
    dag.resize(scc + 1);
    std::vector<int> indeg(scc + 1);
    for(int i = 0; i <= n; i++) {
        for(int v : g[i]) {
            if(id[i] != id[v]) {
                dag[id[i]].push_back(id[v]);
                indeg[id[v]]++;
            }
        }
    }
    for(int i = 1; i <= scc; i++) {
        std::sort(dag[i].begin(), dag[i].end());
        dag[i].erase(std::unique(dag[i].begin(), dag[i].end()), dag[i].end());
    }
    std::fill(indeg.begin(), indeg.end(), 0);
    for(int i = 1; i <= scc; i++) {
        for(int v : dag[i]) indeg[v]++;
    }
    int root = id[0];
    for(int i = 1; i <= scc; i++) {
        if(i != root && indeg[i] == 0) dag[root].push_back(i);
    }
    sumspace.resize(scc + 1);
    sumvalue.resize(scc + 1);
    dp.assign(scc + 1, std::vector<int>(m + 1, -1));
    dfs(root);
    std::cout << std::max(0, dp[root][m]) << '\n';
    return 0;
}
