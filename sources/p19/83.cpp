// P1983 [NOIP 2013 普及组] 车站分级
// https://www.luogu.com.cn/problem/P1983

#include<bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n + 1, std::vector<int>(n + 1, 0));
    std::vector<int> in(n + 1, 0), dp(n + 1, 1);
    std::vector<bool> stop(n + 1, false);
    for (int i = 1; i <= n; i++) {
        int s;
        std::cin >> s;
        std::vector<int> a(s);
        for (int j = 0; j < s; j++) {
            std::cin >> a[j];
        }
        std::fill(stop.begin(), stop.end(), false);
        for (int x: a) {
            stop[x] = true;
        }
        for (int j = a.front(); j <= a.back(); j++) {
            if (stop[j]) continue;
            for (int x: a) {
                if (!g[j][x]) {
                    g[j][x] = 1;
                    in[x]++;
                }
            }
        }
    }
    std::queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    int ans = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ans = std::max(ans, dp[u]);
        for (int v = 1; v <= n; v++) {
            if (!g[u][v]) continue;
            dp[v] = std::max(dp[v], dp[u] + 1);
            in[v]--;
            if (in[v] == 0) {
                q.push(v);
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}