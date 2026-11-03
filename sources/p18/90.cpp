// P1890 gcd 区间
// https://www.luogu.com.cn/problem/P1890

#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> lg(n + 1);
    for (int i = 2; i <= n; i++) {
        lg[i] = lg[i / 2] + 1;
    }
    std::vector<std::vector<int>> st(n + 1, std::vector<int>(lg[n] + 1));
    for (int i = 1; i <= n; i++) {
        st[i][0] = a[i];
    }
    for (int j = 1; j <= lg[n]; j++) {
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            st[i][j] = std::gcd(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    while (m--) {
        int l, r;
        std::cin >> l >> r;
        int k = lg[r - l + 1];
        std::cout << std::gcd(st[l][k], st[r - (1 << k) + 1][k]) << '\n';
    }
    return 0;
}