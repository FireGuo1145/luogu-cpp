// P1048 [NOIP 2005 普及组] 采药
// https://www.luogu.com.cn/problem/P1048

#include<bits/stdc++.h>

int main() {
    int T, m;
    std::cin >> T >> m;
    std::vector<int> t(m + 1), v(m + 1), dp(T + 1, 0);
    for (int i = 1; i <= m; i++) {
        std::cin >> t[i] >> v[i];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = T; j >= t[i]; j--) {
            if (j >= t[i]) {
                dp[j] = std::max(dp[j], dp[j - t[i]] + v[i]);
            }
        }
    }
    std::cout << dp[T] << std::endl;
    return 0;
}