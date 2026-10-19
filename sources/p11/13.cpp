// P1113 [USACO02FEB] 杂务
// https://www.luogu.com.cn/problem/P1113

#include<bits/stdc++.h>

int main() {
    int n, id, len, pre, ans = 0;
    std::vector<int> dp(100001, 0);
    std::cin >> n;
    for(int i = 1; i <= n; i++) {
        std::cin >> id >> len;
        while (std::cin >> pre && pre) {
            dp[id] = std::max(dp[id], dp[pre]);
        }
        dp[id] += len;
        ans = std::max(ans, dp[id]);
    }
    std::cout << ans;
    return 0;
}