// P1908 逆序对
// https://www.luogu.com.cn/problem/P1908

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
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        b[i] = a[i];
    }
    std::sort(b.begin(), b.end());
    b.erase(std::unique(b.begin(), b.end()), b.end());
    for (int i = 0; i < n; i++) {
        a[i] = std::lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
    }
    std::vector<int> t(n + 1, 0);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += i - query(t, a[i]);
        add(t, a[i], n);
    }
    std::cout << ans << std::endl;
    return 0;
}