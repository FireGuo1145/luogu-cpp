// B. 两枚齿轮的午后

#include <bits/stdc++.h>

long long getgcdforand(int n) {
    if (n <= 1) return 2;
    long long best = 1 + n * n;
    int s = std::sqrt(n);
    int low = std::max(1, s - 200);
    int high = s + 200;
    for (int a = low; a <= high; ++a) {
        long long start_b = std::max((long long)a, (long long)(n + a - 1) / a);
        for (long long b = start_b; b <= start_b + 50; ++b) {
            if ((long long)a / std::gcd(a, b) * b >= n) {
                best = std::min(best, (long long)a * a + b * b);
                break;
            }
        }
    }
    return best;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int n;
        std::cin >> n;
        std::cout << getgcdforand(n) << std::endl;
    }
}