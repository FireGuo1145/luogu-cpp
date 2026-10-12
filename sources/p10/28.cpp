// P1028 [NOIP 2001 普及组] 数的计算
// https://www.luogu.com.cn/problem/P1028

#include<bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        long long sum = 0;
        for (int j = 1; j <= i / 2; j++) {
            sum += dp[j];
        }
        dp[i] = sum + 1;
    }
    std::cout << dp[n] << std::endl;
    return 0;
}