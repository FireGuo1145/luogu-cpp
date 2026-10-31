// P9233 [蓝桥杯 2023 省 A] 颜色平衡树
// https://www.luogu.com.cn/problem/P9233

#include<bits/stdc++.h>

std::vector<std::vector<int>> g;
std::vector<int> c;
std::vector<int> siz;
std::vector<int> heavy;
std::vector<int> cnt;
std::vector<int> ccnt;

int n, ans = 0, kinds = 0;

void dfs(int u) {
    siz[u] = 1;
    for (int v : g[u]) {
        dfs(v);
        siz[u] += siz[v];
        if (siz[v] > siz[heavy[u]]) {
            heavy[u] = v;
        }
    }
}
void modify(int color, int dt) {
    int old = cnt[color];
    if (old > 0) {
        ccnt[old]--;
        if (ccnt[old] == 0) {
            kinds--;
        }
    }
    cnt[color] += dt;
    int now = cnt[color];
    if (now > 0) {
        if (ccnt[now] == 0) {
            kinds++;
        }
        ccnt[now]++;
    }
}
void add(int u, int dt) {
    modify(c[u], dt);
    for (int v : g[u]) {
        add(v, dt);
    }
}
void calc(int u, bool save) {
    for (int v : g[u]) {
        if (v != heavy[u]) {
            calc(v, false);
        }
    }
    if (heavy[u] != 0) {
        calc(heavy[u], true);
    }
    modify(c[u], 1);
    for (int v : g[u]) {
        if (v != heavy[u]) {
            add(v, 1);
        }
    }
    if (kinds == 1) {
        ans++;
    }
    if (!save) {
        add(u, -1);
    }
}

int main() {
    std::cin >> n;
    g.resize(n + 1);
    c.resize(n + 1);
    siz.resize(n + 1);
    heavy.resize(n + 1);
    cnt.resize(200001);
    ccnt.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        int f;
        std::cin >> c[i] >> f;
        if (f != 0) {
            g[f].push_back(i);
        }
    }
    dfs(1);
    calc(1, true);
    std::cout << ans << std::endl;
    return 0;
}