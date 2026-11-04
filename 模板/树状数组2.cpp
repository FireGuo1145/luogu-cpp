#include <bits/stdc++.h>

int n, m;
std::vector<long long> t;

int lowbit(int x) {
    return x & -x;
}

void add(int x, long long k) {
    while (x <= n) {
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
    std::cin >> n >> m;
    t.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        long long x;
        std::cin >> x;
        add(i, x);
        add(i + 1, -x);
    }
    while (m--) {
        int op, x, y;
        long long k;
        std::cin >> op >> x;
        if (op == 1) {
            std::cin >> y >> k;
            add(x, k);
            add(y + 1, -k);
        } else {
            std::cout << query(x) << std::endl;
        }
    }
    return 0;
}