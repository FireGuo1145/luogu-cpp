// P1616 疯狂的采药
// https://www.luogu.com.cn/problem/P1616

#include<bits/stdc++.h>

int main() {
    int T, m;
    std::cin >> T >> m;
    std::vector<long long> t(m + 1), v(m + 1), dp(T + 1, 0);
    for (int i = 1; i <= m; i++) {
        std::cin >> t[i] >> v[i];
    }
    for (int i = 1; i <= T; i++) {
        for (int j = 1; j <= m; j++) {
            if (i >= t[j]) {
                dp[i] = std::max(dp[i], dp[i - t[j]] + v[j]);
            }
        }
    }
    std::cout << dp[T] << std::endl;
    return 0;
}