#include <bits/stdc++.h>

// 注意是先乘后加，然后更新懒值的时候如果是加就只变 add，如果是乘那么 mul 和 add 都要变

long long n, m, mod;    // 数字个数、操作个数、模数
std::vector<long long> a, sum, lazyMul, lazyAdd;    // 每个区间的值、区间总和、懒值

void pushup(long long p) {
    sum[p] = (sum[p * 2] + sum[p * 2 + 1]) % mod;
}

void pushdown(long long p, long long l, long long r) {
    long long mid = (l + r) / 2;
    long long lc = p * 2, rc = p * 2 + 1;
    sum[lc] = (sum[lc] * lazyMul[p] + lazyAdd[p] * (mid - l + 1)) % mod;
    sum[rc] = (sum[rc] * lazyMul[p] + lazyAdd[p] * (r - mid)) % mod;
    lazyMul[lc] = lazyMul[lc] * lazyMul[p] % mod;
    lazyMul[rc] = lazyMul[rc] * lazyMul[p] % mod;
    lazyAdd[lc] = (lazyAdd[lc] * lazyMul[p] + lazyAdd[p]) % mod;
    lazyAdd[rc] = (lazyAdd[rc] * lazyMul[p] + lazyAdd[p]) % mod;
    lazyMul[p] = 1;
    lazyAdd[p] = 0;
}

void build(long long p, long long l, long long r) {
    lazyMul[p] = 1;
    lazyAdd[p] = 0;
    if (l == r) {
        sum[p] = a[l] % mod;
        return;
    }
    long long mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    pushup(p);
}

void updateMul(long long p, long long l, long long r, long long x, long long y, long long k) {
    if (x <= l && r <= y) {
        sum[p] = sum[p] * k % mod;
        lazyMul[p] = lazyMul[p] * k % mod;
        lazyAdd[p] = lazyAdd[p] * k % mod;
        return;
    }
    pushdown(p, l, r);
    long long mid = (l + r) / 2;
    if (x <= mid) updateMul(p * 2, l, mid, x, y, k);
    if (y > mid) updateMul(p * 2 + 1, mid + 1, r, x, y, k);
    pushup(p);
}

void updateAdd(long long p, long long l, long long r, long long x, long long y, long long k) {
    if (x <= l && r <= y) {
        sum[p] = (sum[p] + k * (r - l + 1)) % mod;
        lazyAdd[p] = (lazyAdd[p] + k) % mod;
        return;
    }
    pushdown(p, l, r);
    long long mid = (l + r) / 2;
    if (x <= mid) updateAdd(p * 2, l, mid, x, y, k);
    if (y > mid) updateAdd(p * 2 + 1, mid + 1, r, x, y, k);
    pushup(p);
}

long long query(long long p, long long l, long long r, long long x, long long y) {
    if (x <= l && r <= y) return sum[p];
    pushdown(p, l, r);
    long long mid = (l + r) / 2;
    long long ans = 0;
    if (x <= mid) ans = (ans + query(p * 2, l, mid, x, y)) % mod;
    if (y > mid) ans = (ans + query(p * 2 + 1, mid + 1, r, x, y)) % mod;
    return ans;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> mod;
    a.resize(n + 1);
    sum.resize(n * 4 + 5);
    lazyMul.resize(n * 4 + 5, 1);
    lazyAdd.resize(n * 4 + 5, 0);
    for (long long i = 1; i <= n; i++) std::cin >> a[i];
    build(1, 1, n);
    while (m--) {
        long long op, x, y, k;
        std::cin >> op >> x >> y;
        if (op == 1) {
            std::cin >> k;
            updateMul(1, 1, n, x, y, k);
        } else if (op == 2) {
            std::cin >> k;
            updateAdd(1, 1, n, x, y, k);
        } else {
            std::cout << query(1, 1, n, x, y) % mod << std::endl;
        }
    }
    return 0;
}
