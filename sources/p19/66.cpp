// P1966 [NOIP 2013 提高组] 火柴排队
// https://www.luogu.com.cn/problem/P1966

#include <bits/stdc++.h>

int lowbit(int x) {
    return x & -x;
}
void add(std::vector<int>& t, int x, int n) {   // 这个数出现了一次
    while (x <= n) {
        t[x]++;
        x += lowbit(x);
    }
}
int query(std::vector<int>& t, int x) { // 找某个数之前出现了几次
    int ans = 0;
    while (x > 0) {
        ans += t[x];
        x -= lowbit(x);
    }
    return ans;
}
int main() {
    int n;
    std::cin >> n;
    std::vector<std::pair<int,int>> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i].first;
        b[i].second = i;
    }
    std::sort(b.begin(), b.end());
    std::sort(a.begin(), a.end());
    std::vector<int> c(n);
    for (int i = 0; i < n; i++) {
        c[a[i].second] = b[i].second;
    }
    std::vector<int> d(n);
    for (int i = 0; i < n; i++) {
        d[i] = c[i];
    }
    std::sort(d.begin(), d.end());
    d.erase(std::unique(d.begin(), d.end()), d.end());
    for (int i = 0; i < n; i++) {
        c[i] = std::lower_bound(d.begin(), d.end(), c[i]) - d.begin() + 1;
    }
    std::vector<int> t(n + 1, 0);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += i - query(t, c[i]);
        add(t, c[i], n);
    }
    std::cout << ans % 99999997 << std::endl;
    return 0;
}