// U744923 萌新赛模拟赛T4
// https://www.luogu.com.cn/problem/U744923
// 你是有多喜欢芭菲。。。

#include<bits/stdc++.h>

int main() {
    int n, L;
    long long c;
    std::cin >> n >> L >> c;
    std::vector<long long> a(n + 1, 0), s(n + 1, 0), dp(n + 1, 0);
    // std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));    // dp[day][times]
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    long long mx = -1;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (i >= L) {
            int j = i - L + 1;
            mx = std::max(mx, dp[j - 1] - s[j - 1]);
            dp[i] = std::max(dp[i], s[i] - c + mx);
        }
    }
    std::cout << dp[n] << std::endl;
    return 0;
}