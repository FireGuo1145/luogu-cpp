// P17828 [CSP-J 2026] 回文串 / string（民间数据）
// https://www.luogu.com.cn/problem/P17828

#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<long long> a(n);
    std::vector<char> c(n);
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> c[i];
        sum += a[i];
    }
    int i = 0, j = n - 1;
    long long l = a[i], r = a[j];
    long long ans = 0;
    long long need = sum / 2;
    while (need > 0) {
        long long k = std::min({l, r, need});
        if (c[i] != c[j]) {
            ans += k;
        }
        l -= k;
        r -= k;
        need -= k;
        if (l == 0 && need > 0) {
            i++;
            l = a[i];
        }
        if (r == 0 && need > 0) {
            j--;
            r = a[j];
        }
    }
    std::cout << ans << std::endl;
    return 0;
}