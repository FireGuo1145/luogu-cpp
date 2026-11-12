// P4513 小白逛公园
// https://www.luogu.com.cn/problem/P4513
// 谁再出这种题我跟谁急眼

#include <bits/stdc++.h>

long long n, m;
std::vector<long long> a, sum, lmax, rmax, ans;

// 依旧向上传
// 哦对了还要兼顾左右段最大值的计算
void pushup(long long p) {
    sum[p] = sum[p * 2] + sum[p * 2 + 1];
    lmax[p] = std::max(lmax[p * 2], sum[p * 2] + lmax[p * 2 + 1]);
    rmax[p] = std::max(rmax[p * 2 + 1], sum[p * 2 + 1] + rmax[p * 2]);
    ans[p] = std::max({ans[p * 2], ans[p * 2 + 1], rmax[p * 2] + lmax[p * 2 + 1]});
}

// mad这可能是最简单的地方了
void build(long long p, long long l, long long r) {
    if (l == r) {
        sum[p] = lmax[p] = rmax[p] = ans[p] = a[l];
        return;
    }
    long long mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    pushup(p);
}

void update(long long p, long long l, long long r, long long pos, long long val) {
    if (l == r) {
        sum[p] = lmax[p] = rmax[p] = ans[p] = val;
        return;
    }
    long long mid = (l + r) / 2;
    if (pos <= mid) update(p * 2, l, mid, pos, val);
    else update(p * 2 + 1, mid + 1, r, pos, val);
    pushup(p);
}

// 最大的子段和有几种情况
// 首先是全都在左端，然后是全都在右端，然后是跨越
// 跨越的情况是左端的右端最大值加上右端的左端最大值
// 而右端最大值的算法是右端的总和加上左端的右端最大值，以此类推
// 左端最大值同理
// 过于何意味了
void query(long long p, long long l, long long r, long long ql, long long qr, long long &s, long long &lm, long long &rm, long long &res) {
    if (ql <= l && r <= qr) {
        s = sum[p];
        lm = lmax[p];
        rm = rmax[p];
        res = ans[p];
        return;
    }
    long long mid = (l + r) / 2;
    if (qr <= mid) {
        query(p * 2, l, mid, ql, qr, s, lm, rm, res);
        return;
    }
    if (ql > mid) {
        query(p * 2 + 1, mid + 1, r, ql, qr, s, lm, rm, res);
        return;
    }
    long long ls, llm, lrm, lans;
    long long rs, rlm, rrm, rans;
    query(p * 2, l, mid, ql, qr, ls, llm, lrm, lans);
    query(p * 2 + 1, mid + 1, r, ql, qr, rs, rlm, rrm, rans);
    s = ls + rs;
    lm = std::max(llm, ls + rlm);
    rm = std::max(rrm, rs + lrm);
    res = std::max({lans, rans, lrm + rlm});
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    a.resize(n + 1);
    sum.resize(n * 4 + 4);
    lmax.resize(n * 4 + 4);
    rmax.resize(n * 4 + 4);
    ans.resize(n * 4 + 4);
    for (long long i = 1; i <= n; i++) std::cin >> a[i];
    build(1, 1, n);
    while (m--) {
        long long k, x, y;
        std::cin >> k >> x >> y;
        if (k == 1) {
            if (x > y) std::swap(x, y);
            long long s, lm, rm, res;
            query(1, 1, n, x, y, s, lm, rm, res);
            std::cout << res << std::endl;
        } else {
            update(1, 1, n, x, y);
        }
    }
    return 0;
}
