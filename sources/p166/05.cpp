// @Title: P16605 [SYSUCPC 2025] Sum
// @Link: https://www.luogu.com.cn/problem/P16605
// @Author: FireGuo
// @Time: 2026-11-16 10:04

#include <bits/stdc++.h>

long long calcsum(long long n, long long base) {
    long long sum = 0;
    while (n > 0) {
        sum += n % base;
        n /= base;
    }
    return sum;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int T;
    std::cin >> T;
    while (T--) {
        long long n, r;
        std::cin >> n >> r;
        if (r >= n) {
            std::cout << 1 << std::endl;
        } else {
            long long ans = n;
            long long s = std::sqrt(n);
            long long small_end = std::min(r, s);
            for (long long b = 2; b <= small_end; ++b) {
                ans = std::min(ans, calcsum(n, b));
            }
            for (long long l = s + 1, right; l <= r; l = right + 1) {
                long long q = n / l;
                right = std::min(r, n / q);
                long long digit_sum = n - q * (right - 1);
                ans = std::min(ans, digit_sum);
            }
            std::cout << ans << std::endl;
        }
    }
    return 0;
}