// B3609 [图论与代数结构 701] 强连通分量
// https://www.luogu.com.cn/problem/B3609

#include<bits/stdc++.h>

std::vector<int> dfn, low, instack, id; // dfn: 时间 low: 能到达的最早的时间 instack: 是不是在栈里面 id: 属于哪个分量
std::vector<std::vector<int>> g, ans;   // g: 原图 ans: 缩点后的图
std::stack<int> s;  // 栈
std::vector<bool> printed;  // 标记是不是输出过
int n, m, cnt, top, scc;    // n: 点数 m: 边数 cnt: 时间 top: 栈顶 scc: 分量数

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
            ans[scc].push_back(v);
            if (v == u) break;
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
    ans.resize(n + 1);
    printed.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) tarjan(i);
    }
    std::cout << scc << std::endl;
    for (int i = 1; i <= scc; ++i) {
        std::sort(ans[i].begin(), ans[i].end());
    }
    for (int i = 1; i <= n; ++i) {
        if (!printed[id[i]]) {
            for (int j : ans[id[i]]) {
                std::cout << j << " ";
                printed[id[j]] = true;
            }
            std::cout << std::endl;
        }
    }
    return 0;
}