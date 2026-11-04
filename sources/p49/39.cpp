// P4939 Agent2
// https://www.luogu.com.cn/problem/P4939

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
    while (m--) {
        int op, x;
        long long y;
        std::cin >> op >> x;
        if (op == 0) {
            std::cin >> y;
            add(x, 1);
            add(y + 1, -1);
        } else {
            std::cout << query(x) << std::endl;
        }
    }
    return 0;
}