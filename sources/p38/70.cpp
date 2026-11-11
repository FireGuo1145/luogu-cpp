// P3870 [TJOI2009] 开关
// https://www.luogu.com.cn/problem/P3870

#include <bits/stdc++.h>
long long n, m;
std::vector<long long> a, sum, lazy;

void pushup(long long p) {  // 向上传，用于生成
    sum[p] = sum[p * 2] + sum[p * 2 + 1];
}

void pushdown(long long p, long long l, long long r) {  // 向下传，用于更新懒参数
    if (lazy[p] == 0) return;
    long long mid = (l + r) / 2;
    long long k = lazy[p];
    // sum[p * 2] += k * (mid - l + 1);    // 自己的两个分量分别加上懒参数
    // sum[p * 2 + 1] += k * (r - mid);
    sum[p * 2] = (mid - l + 1) - sum[p * 2];
    sum[p * 2 + 1] = (r - mid) - sum[p * 2 + 1];
    lazy[p * 2] ^= k;   // 自己的两个分量的懒参数分别加上上面的懒参数
    lazy[p * 2 + 1] ^= k;
    lazy[p] = 0;
}

void build(long long p, long long l, long long r) { // 构建
    if (l == r) {
        sum[p] = a[l];
        return;
    }
    long long mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    pushup(p);
}

void update(long long p, long long l, long long r, long long L, long long R, long long k) { // 添加区间的值
    if (L <= l && r <= R) {
        // sum[p] += k * (r - l + 1);
        sum[p] = (r - l + 1) - sum[p];
        lazy[p] ^= k;
        return;
    }
    pushdown(p, l, r);  // 往下传懒参数
    long long mid = (l + r) / 2;
    if (L <= mid)
        update(p * 2, l, mid, L, R, k);
    if (R > mid)
        update(p * 2 + 1, mid + 1, r, L, R, k);
    pushup(p);
}

long long query(long long p, long long l, long long r, long long L, long long R) {  // 查询
    if (L <= l && r <= R)
        return sum[p];
    pushdown(p, l, r);
    long long mid = (l + r) / 2;
    long long ans = 0;
    if (L <= mid)
        ans += query(p * 2, l, mid, L, R);
    if (R > mid)
        ans += query(p * 2 + 1, mid + 1, r, L, R);
    return ans;
}

int main() {
    std::cin >> n >> m;
    a.resize(n + 1);
    sum.resize(n * 4 + 5, 0);
    lazy.resize(n * 4 + 5, 0);
    for (long long i = 1; i <= n; i++)
        a[i] = 0;
    build(1, 1, n);
    while (m--) {
        long long op, x, y;
        std::cin >> op >> x >> y;
        if (op == 0) {
            update(1, 1, n, x, y, 1);
        } else {
            std::cout << query(1, 1, n, x, y) << std::endl;
        }
    }
    return 0;
}