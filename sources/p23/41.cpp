// P2341 [USACO03FALL / HAOI2006] 受欢迎的牛 G
// https://www.luogu.com.cn/problem/P2341

#include<bits/stdc++.h>

std::vector<int> dfn, low, instack, id, orin; // dfn: 时间 low: 能到达的最早的时间 instack: 是不是在栈里面 id: 属于哪个分量 orin: 原来点量
std::vector<std::vector<int>> g, dag;   // g: 原图 dag: 缩点后的图
std::stack<int> s;  // 栈
int n, m, cnt, scc;    // n: 点数 m: 边数 cnt: 时间 top: 栈顶 scc: 分量数

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
            ++orin[scc];
            if (v == u) break;
        }
    }
}

int main() {
    std::cin >> n >> m;
    g.resize(n + 1);
    dfn.resize(n + 1);
    dag.resize(n + 1);
    low.resize(n + 1);
    instack.resize(n + 1);
    id.resize(n + 1);
    orin.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    std::vector<int> out(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j : g[i]) {
            if (id[i] != id[j]) {
                ++out[id[i]];
            }
        }
    }
    int outcount = 0;
    for (int i = 1; i <= scc; i++) {
        if (out[i] == 0) continue;
        ++outcount;
    }
    if (outcount == scc - 1) {
        for (int i = 1; i <= scc; i++) {
            if (out[i] == 0) {
                std::cout << orin[i] << std::endl;
                return 0;
            }
        }
    } else if (outcount == scc) {
        std::cout << n << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    return 0;
}