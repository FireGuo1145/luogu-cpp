// @Title: P12751 [POI 2017 R2] 集装箱 Shipping containers
// @Link: https://www.luogu.com.cn/problem/P12751
// @Author: FireGuo
// @Time: 2026-11-17 04:03

#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    int s = std::sqrt(n);
    std::vector<std::vector<int>> diff(s + 1, std::vector<int>(n + 1, 0));
    std::vector<int> b(n + 1);
    for (int i = 0; i < k; i++) {
        long long a, l, d;
        std::cin >> a >> l >> d;
        if (d > s) {
            for (int j = 0; j < l; j++) {
                b[a + j * d]++;
            }
        } else {
            diff[d][a]++;
            if (a + l * d <= n) {
                diff[d][a + l * d]--;
            }
        }
    }
    for (int d = 1; d <= s; d++) {
        for (int j = d + 1; j <= n; j++) {
            diff[d][j] += diff[d][j - d];
        }
        for (int j = 1; j <= n; j++) {
            b[j] += diff[d][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}