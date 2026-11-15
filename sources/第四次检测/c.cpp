// C. 纸盒里的小小春日

#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<std::pair<long long, long long>> v, next;//存一下之前的gcd
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        next.clear();
        next.push_back({a[i], 1});
        for (auto p : v) {
            long long g = std::gcd(p.first, a[i]);
            if (next.back().first == g) {
                next.back().second += p.second;
            } else {
                next.push_back({g, p.second});
            }
        }
        for (auto p : next) {
            if (p.first == 1) ans += p.second;
        }
        v = next;
    }
    std::cout << ans << std::endl;
    return 0;
}
