// P3387 【模板】缩点 / 强连通分量
// https://www.luogu.com.cn/problem/P3387

#include<bits/stdc++.h>

std::vector<int> dfn, low, instack, id; // dfn: 时间 low: 能到达的最早的时间 instack: 是不是在栈里面 id: 属于哪个分量
std::vector<std::vector<int>> g, dag;   // g: 原图 dag: 缩点后的图
std::stack<int> s;  // 栈
int n, m, cnt, top, scc;    // n: 点数 m: 边数 cnt: 时间 top: 栈顶 scc: 分量数

void tarjan(int u) {    // u: 当前点
    dfn[u] = low[u] = ++cnt;    // 时间
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
            if (v == u) break;
        }
    }
}

int main() {
    std::cin >> n >> m;
    dfn.resize(n + 1);
    low.resize(n + 1);
    instack.resize(n + 1);
    id.resize(n + 1);
    g.resize(n + 1);
    dag.resize(n + 1);
    std::vector<int> v1(n + 1), v2(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> v1[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
    }
    // 缩点
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= scc; i++) {
        int sum = 0;
        for (int j : dag[i]) {
            sum += v1[j];
        }
        v2[i] = sum;
        dag[i].clear();
    }
    for (int u = 1; u <= n; u++) {
        for (int v : g[u]) {
            if (id[u] != id[v]) {
                dag[id[u]].push_back(id[v]);
            }
        }
    }
    std::vector<int> dp(scc + 1, 0);
    for (int i = scc; i >= 1; i--) {
        dp[i] = std::max(dp[i], v2[i]);
        for (int j : dag[i]) {
            dp[j] = std::max(dp[j], dp[i] + v2[j]);
        }
    }
    std::cout << *std::max_element(dp.begin(), dp.end()) << std::endl;
    return 0;
}