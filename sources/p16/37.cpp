// P1637 三元上升子序列
// https://www.luogu.com.cn/problem/P1637

#include <bits/stdc++.h>

int n;
std::vector<long long> t;

int lowbit(int x) {
    return x & -x;
}

void add(int x, long long k) {
    while (x <= 100000) {
        t[x] += k;
        x += lowbit(x);
    }
}

long long query(int x) {
    long long ans = 0;
    while (x > 0) {
        ans += t[x];
        x -= lowbit(x);
    }
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    t.resize(100001);
    std::vector<int> a(n + 1), l(n + 1), r(n + 1);
    for (int i = 1; i <= n; i++) {
        std::cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        l[i] = query(a[i] - 1);
        add(a[i], 1);
    }
    fill(t.begin(), t.end(), 0);
    for (int i = n; i >= 1; i--) {
        r[i] = (n - i) - query(a[i]);
        add(a[i], 1);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1LL * l[i] * r[i];
    }
    std::cout << ans << std::endl;
    return 0;
}