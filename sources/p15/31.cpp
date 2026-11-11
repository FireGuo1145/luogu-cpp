// P1531 I Hate It
// https://luogu.com.cn/problem/P1531

#include <bits/stdc++.h>
long long n, m;
std::vector<long long> a, sum;

void pushup(long long p) {  // 向上传，用于生成
    sum[p] = std::max(sum[p * 2], sum[p * 2 + 1]);
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
        sum[p] = std::max(sum[p], k);
        return;
    }
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
    long long mid = (l + r) / 2;
    long long ans = LLONG_MIN;
    if (L <= mid)
        ans = std::max(ans, query(p * 2, l, mid, L, R));
    if (R > mid)
        ans = std::max(ans, query(p * 2 + 1, mid + 1, r, L, R));
    return ans;
}

int main() {
    std::cin >> n >> m;
    a.resize(n + 1);
    sum.resize(n * 4 + 5, 0);
    for (long long i = 1; i <= n; i++)
        std::cin >> a[i];
    build(1, 1, n);
    while (m--) {
        long long x, y;
        std::string op;
        std::cin >> op >> x >> y;
        if (op == "U") {
            update(1, 1, n, x, x, y);
        } else {
            std::cout << query(1, 1, n, x, y) << std::endl;
        }
    }
    return 0;
}