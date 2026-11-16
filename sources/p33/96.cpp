// @Title: P3396 哈希冲突
// @Link: https://www.luogu.com.cn/problem/P3396
// @Author: FireGuo
// @Time: 2026-11-16 03:46

#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    int B = static_cast<int>(std::sqrt(n));// 取平方根作为阈值
    if (B == 0) B = 1;
    std::vector<std::vector<int>> ans(B + 1, std::vector<int>(B + 1, 0));// ans[i][j]表示模数为i、余数为j的所有值总和
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
        for (int x = 1; x <= B; ++x) {
            ans[x][i % x] += a[i];// 预先算好小的
        }
    }
    for (int i = 0; i < m; ++i) {
        char op;
        int x, y;
        std::cin >> op >> x >> y;
        if (op == 'C') { 
            int diff = y - a[x];
            a[x] = y;
            for (int mod = 1; mod <= B; ++mod) {
                ans[mod][x % mod] += diff;
            }
        } 
        else if (op == 'A') { 
            if (x <= B) {
                std::cout << ans[x][y] << std::endl;
            } else {
                int sum = 0;
                int start = (y == 0 ? x : y);
                for (int j = start; j <= n; j += x) {
                    sum += a[j];// 推算
                }
                std::cout << sum << std::endl;
            }
        }
    }
}
