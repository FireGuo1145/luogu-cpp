// C. 黑板上的最后一格

#include <bits/stdc++.h>

std::vector<int> a;

long long solvezhuzi(int l, int r, int caleh) {
    if (l > r) return 0;
    auto minh = std::min_element(a.begin() + l, a.begin() + r + 1);
    long long minhi = *minh;
    int minidx = std::distance(a.begin(), minh);
    long long ops = minhi - caleh;
    ops += solvezhuzi(l, minidx - 1, minhi);
    ops += solvezhuzi(minidx + 1, r, minhi);
    return std::min((long long)(r - l + 1), ops);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    a.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    long long allops = solvezhuzi(1, n, 0);
    std::cout << allops << std::endl;
}