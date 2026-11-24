// A. 等长街亮起来

#include <bits/stdc++.h>

int main() {
    int T;
    std::cin >> T;
    for (int i = 1; i <= T; i++) {
        long long n, a;
        std::cin >> n >> a;
        long long min = -1;
        for (long long r = 0; r <= n; ++r) {
            long long all = 2 * r + 1;
            long long corrent = (n + all - 1) / all;
            long long cost = corrent * (a + r * r);
            if (min == -1 || cost < min) {
                min = cost;
            } else if (corrent == 1) {
                break;
            }
        }
        std::cout << min << std::endl;
    }
    return 0;
}