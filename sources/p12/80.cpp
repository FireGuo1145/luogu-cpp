// P1280 [CHCI 2002 National Competition #2 Juniors] 尼克的任务
// https://www.luogu.com.cn/problem/P1280

#include<bits/stdc++.h>

int main() {
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> p(n + 1);
    for (int i = 1; i <= k; i++) {
        int s, t;
        std::cin >> s >> t;
        p[s].push_back(t);
    }
    std::vector<int> dp(n + 2, 0);
    for (int i = n; i >= 1; i--) {
        if (p[i].empty()) {
            dp[i] = dp[i + 1] + 1;
        } else {
            for (int t : p[i]) {
                dp[i] = std::max(dp[i], dp[i + t]);
            }
        }
    }
    std::cout << dp[1] << std::endl;
    return 0;
}