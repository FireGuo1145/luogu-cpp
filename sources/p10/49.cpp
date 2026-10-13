// P1049 [NOIP 2001 普及组] 装箱问题
// https://www.luogu.com.cn/problem/P1049

#include<bits/stdc++.h>

int main() {
    int v, n;
    std::cin >> v >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> a[i];
    std::vector<int> dp(v + 1, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = v; j >= a[i]; j--) {
            dp[j] = std::max(dp[j], dp[j - a[i]] + a[i]);
        }
    }
    std::cout << v - dp[v] << std::endl;
    return 0;
}