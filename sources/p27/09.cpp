// @Title: P2709 【模板】莫队 / 小 B 的询问
// @Link: https://www.luogu.com.cn/problem/P2709
// @Author: FireGuo
// @Time: 2026-11-18 10:25

#include <bits/stdc++.h>

struct Query {
    int l, r, id;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    std::vector<Query> q(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    int sz = std::sqrt(n);
    std::sort(q.begin(), q.end(), [&](const Query &x, const Query &y) {
        int bx = x.l / sz;
        int by = y.l / sz;
        if (bx != by) {
            return bx < by;
        }
        return (bx & 1) ? x.r < y.r : x.r > y.r;
    });
    std::vector<long long> ans(m);
    std::vector<int> cnt(k + 1, 0);
    int l = 1, r = 0;
    long long current = 0;
    for (int i = 0; i < m; ++i) {
        while (l > q[i].l) {
            --l;
            current += 2LL * cnt[a[l]] + 1;
            ++cnt[a[l]];
        }
        while (r < q[i].r) {
            ++r;
            current += 2LL * cnt[a[r]] + 1;
            ++cnt[a[r]];
        }
        while (l < q[i].l) {
            current -= 2LL * cnt[a[l]] - 1;
            --cnt[a[l]];
            ++l;
        }
        while (r > q[i].r) {
            current -= 2LL * cnt[a[r]] - 1;
            --cnt[a[r]];
            --r;
        }
        ans[q[i].id] = current;
    }
    for (int i = 0; i < m; ++i) {
        std::cout << ans[i] << std::endl;
    }
    return 0;
}