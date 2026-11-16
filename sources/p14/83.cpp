// @Title: P1483 序列变换
// @Link: https://www.luogu.com.cn/problem/P1483
// @Author: FireGuo
// @Time: 2026-11-16 11:03

#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<long long> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }

    // add[x] 记录针对因数 x 的累计加数
    std::vector<long long> add(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        int op;
        std::cin >> op;
        if (op == 1) {
            int x, y;
            std::cin >> x >> y;
            add[x] += y;
        } else {
            int x;
            std::cin >> x;
            long long ori = a[x];
            for (int j = 1; j * j <= x; ++j) {
                if (x % j == 0) {
                    ori += add[j];
                    if (j * j != x) {
                        ori += add[x / j];
                    }
                }
            }
            std::cout << ori << std::endl;
        }
    }

    return 0;
}