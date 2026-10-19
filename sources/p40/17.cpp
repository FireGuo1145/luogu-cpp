// P4017 最大食物链计数
// https://www.luogu.com.cn/problem/P4017

#include<bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n + 1); // 邻接表
    std::vector<int> in(n + 1), out(n + 1), dp(n + 1);  //入度、出度、dp
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        g[a].push_back(b);
        in[b]++;
        out[a]++;
    }
    std::queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
            dp[i] = 1;
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            dp[v] = (dp[v] + dp[u]) % 80112002; // 累加？？
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (out[i] == 0) {
            ans = (ans + dp[i]) % 80112002;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}