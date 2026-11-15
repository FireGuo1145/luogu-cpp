// A. 白兔落子时

#include <bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n + 2, std::vector<int>(m + 2));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            char c;
            std::cin >> c;
            if (c == 'W') {
                a[i][j] = 1;
            } else {
                a[i][j] = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i-1][j]==1 || a[i][j-1]==1 || a[i+1][j]==1 || a[i][j+1]==1) {
                if (a[i][j] == 0) {
                    ++ans;
                }
            }
        }
    }
    std::cout << ans << std::endl;
    return 0;
}