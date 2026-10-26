// U744914 萌新赛模拟赛T1
// https://www.luogu.com.cn/problem/U744914

#include<bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n + 1, 0), b(n, 0);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        std::cin >> b[i];
    }
    std::vector<long long> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = a[1];
    for (int i = 2; i <= n; i++) {
        dp[i] = std::max(dp[i - 1] + a[i], dp[i - 2] + b[i - 1]);
    }
    std::cout << dp[n] << std::endl;
    return 0;
}