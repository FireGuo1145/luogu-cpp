// P1156 [USACO01OPEN] 垃圾陷阱
// https://www.luogu.com.cn/problem/P1156

#include<bits/stdc++.h>

int main() {
    int d, g;
    std::cin >> d >> g;
    std::vector<int> t(g + 1), h(g + 1), f(g + 1);
    for (int i = 1; i <= g; i++) std::cin >> t[i] >> f[i] >> h[i];
    std::vector<int> dp(d + 1, -1);
    dp[0] = 10;
    for (int i = 1; i <= g; i++) {
        for (int j = d; j >= 0; j--) {
            if (dp[j] >= t[i]) {
                dp[j + h[i]] = std::max(dp[j + h[i]], dp[j]);
                if (j + h[i] >= d) {
                    std::cout << t[i] << std::endl;
                    return 0;
                }
                dp[j] += f[i];
            }
        }
    }
    std::cout << dp[0] << std::endl;
    return 0;
}