// P5020 [NOIP 2018 提高组] 货币系统
// https://www.luogu.com.cn/problem/P5020

#include<bits/stdc++.h>

int main() {
    int T;
    std::cin >> T;
    std::vector<std::vector<int>> money(T + 1);
    for (int i = 1; i <= T; i++) {
        int t;
        std::cin >> t;
        money[i].resize(t + 1);
        for (int j = 1; j <= t; j++) {
            std::cin >> money[i][j];
        }
    }
    for (int i = 1; i <= T; i++) {
        auto now = money[i];
        std::vector<int> newone;
        std::sort(now.begin() + 1, now.end());
        int maxa = now[now.size() - 1];
        std::vector<bool> dp(maxa + 1, false);
        dp[0] = true;
        for (int j = 1; j < now.size(); j++) {
            if (dp[now[j]]) {
                continue;
            }
            newone.push_back(now[j]);
            for (int k = now[j]; k <= maxa; k++) {
                dp[k] = dp[k] || dp[k - now[j]];
            }
        }
        std::cout << newone.size() << std::endl;
    }
    return 0;
}