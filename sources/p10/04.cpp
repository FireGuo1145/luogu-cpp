// P1004 [NOIP 2000 提高组] 方格取数
// https://www.luogu.com.cn/problem/P1004

#include <bits/stdc++.h>
int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> b(n, std::vector<int>(n, 0));
    std::vector<std::vector<std::vector<int>>> dp(
        2 * n - 1,
        std::vector<std::vector<int>>(
            n,
            std::vector<int>(n, 0)
        )
    );
    while (true) {
        int x, y, a;
        std::cin >> x >> y >> a;
        if (x == 0 && y == 0 && a == 0) break;
        b[x - 1][y - 1] = a;
    }
    dp[0][0][0] = b[0][0];
    for (int k = 1; k <= 2 * n - 2; k++) {
        for (int x1 = 0; x1 < n; x1++) {
            int y1 = k - x1;
            if (y1 < 0 || y1 >= n) continue;
            for (int x2 = 0; x2 < n; x2++) {
                int y2 = k - x2;
                if (y2 < 0 || y2 >= n) continue;
                int best = 0;
                if (x1 > 0 && x2 > 0)
                    best = std::max(best, dp[k - 1][x1 - 1][x2 - 1]);
                if (x1 > 0 && y2 > 0)
                    best = std::max(best, dp[k - 1][x1 - 1][x2]);
                if (y1 > 0 && x2 > 0)
                    best = std::max(best, dp[k - 1][x1][x2 - 1]);
                if (y1 > 0 && y2 > 0)
                    best = std::max(best, dp[k - 1][x1][x2]);
                dp[k][x1][x2] = best + b[x1][y1];
                if (x1 != x2) dp[k][x1][x2] += b[x2][y2];
            }
        }
    }
    std::cout << dp[2 * n - 2][n - 1][n - 1];
    return 0;
}