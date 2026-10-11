// P1006 [NOIP 2008 提高组] 传纸条
// https://www.luogu.com.cn/problem/P1006

#include<bits/stdc++.h>

int main() {
    int m, n;
    std::cin >> m >> n;
    std::vector<std::vector<int>> peoples(m, std::vector<int>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> peoples[i][j];
        }
    }
    std::vector<std::vector<std::vector<int>>> dp(m + n, std::vector<std::vector<int>>(m, std::vector<int>(m, 0))); // 步数、ax、bx
    for (int step = 0; step <= m + n - 2; step++) {
        if (step == 0) {
            dp[step][0][0] = peoples[0][0];
            continue;
        }
        for (int ax = 0; ax < m; ax++) {
            int ay = step - ax;
            if (ay < 0 || ay >= n) continue;
            for (int bx = 0; bx < m; bx++) {
                int by = step - bx;
                if (by < 0 || by >= n) continue;
                if (ax == bx && ax == m - 1) {
                    dp[step][ax][bx] = std::max({
                        dp[step - 1][ax - 1][bx] + peoples[ax][ay],
                        dp[step - 1][ax - 1][bx - 1] + peoples[ax][ay],
                        dp[step - 1][ax][bx - 1] + peoples[ax][ay],
                        dp[step - 1][ax][bx] + peoples[ax][ay]
                    });
                    continue;
                }
                if (ax == bx) continue;
                if (ax <= 0) {
                    dp[step][ax][bx] = std::max(dp[step - 1][ax][bx] + peoples[ax][ay] + peoples[bx][by], dp[step - 1][ax][bx - 1] + peoples[ax][ay] + peoples[bx][by]);
                    continue;
                }
                if (bx <= 0) {
                    dp[step][ax][bx] = std::max(dp[step - 1][ax - 1][bx] + peoples[ax][ay] + peoples[bx][by], dp[step - 1][ax][bx] + peoples[ax][ay] + peoples[bx][by]);
                    continue;
                }
                dp[step][ax][bx] = std::max({
                    dp[step - 1][ax - 1][bx] + peoples[ax][ay],
                    dp[step - 1][ax - 1][bx - 1] + peoples[ax][ay],
                    dp[step - 1][ax][bx - 1] + peoples[ax][ay],
                    dp[step - 1][ax][bx] + peoples[ax][ay]
                });
                dp[step][ax][bx] += peoples[bx][by];
            }
        }
    }
    std::cout << dp[m + n - 2][m - 1][m - 1] << std::endl;
    return 0;
}