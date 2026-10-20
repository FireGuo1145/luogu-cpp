// P2746 [IOI 1996 / USACO5.3] 校园网 Network of Schools
// https://www.luogu.com.cn/problem/P2746

#include<bits/stdc++.h>

std::vector<int> dfn, low, instack, id, orin; // dfn: 时间 low: 能到达的最早的时间 instack: 是不是在栈里面 id: 属于哪个分量 orin: 原来点量
std::vector<std::vector<int>> g, dag;   // g: 原图 dag: 缩点后的图
std::stack<int> s;  // 栈
int n, cnt, scc;    // n: 点数 m: 边数 cnt: 时间 top: 栈顶 scc: 分量数

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
    std::cin >> n;
    g.resize(n + 1);
    dfn.resize(n + 1);
    dag.resize(n + 1);
    low.resize(n + 1);
    instack.resize(n + 1);
    id.resize(n + 1);
    orin.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        while (true) {
            int x;
            std::cin >> x;
            if (x == 0) break;
            g[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    std::vector<int> in(scc + 1, 0), out(scc + 1, 0);
    for (int u = 1; u <= n; u++) {
        for (int v : g[u]) {
            if (id[v] != id[u]) {
                in[id[v]]++;
                out[id[u]]++;
            }
        }
    }
    int ins = 0;
    for (int i = 1; i <= scc; i++) {
        if (in[i] == 0) ++ins;
    }
    std::cout << ins << std::endl;
    int outs = 0;
    for (int i = 1; i <= scc; i++) {
        if (out[i] == 0) ++outs;
    }
    if (scc != 1) {
        std::cout << std::max(ins, outs) << std::endl;
    } else {
        std::cout << 0 << std::endl;
    }
    return 0;
}