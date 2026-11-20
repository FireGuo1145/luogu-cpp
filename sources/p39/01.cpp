// @Title: P3901 数列找不同
// @Link: https://www.luogu.com.cn/problem/P3901
// @Author: FireGuo
// @Time: 2026-11-19 00:00

#include <bits/stdc++.h>

struct Query {
    int l, r, id;
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    std::vector<Query> qu(m);
    for (int i = 0; i < m; ++i) {
        std::cin >> qu[i].l >> qu[i].r;
        qu[i].id = i;
    }
    int sz = std::sqrt(n);
    std::sort(qu.begin(), qu.end(), [&](const Query &x, const Query &y) {
        int bx = x.l / sz;
        int by = y.l / sz;
        if (bx != by) {
            return bx < by;
        }
        return (bx & 1) ? x.r < y.r : x.r > y.r;
    });
    std::vector<bool> ans(m);
    std::vector<int> cnt(100005, 0); 
    int l = 1, r = 0;
    int current = 0;
    for (int i = 0; i < m; ++i) {
        while (l > qu[i].l) {
            --l;
            if (cnt[a[l]] == 0) {
                ++current;
            }
            ++cnt[a[l]];
        }
        while (r < qu[i].r) {
            ++r;
            if (cnt[a[r]] == 0) {
                ++current;
            }
            ++cnt[a[r]];
        }
        while (l < qu[i].l) {
            --cnt[a[l]];
            if (cnt[a[l]] == 0) {
                --current;
            }
            ++l;
        }
        while (r > qu[i].r) {
            --cnt[a[r]];
            if (cnt[a[r]] == 0) {
                --current;
            }
            --r;
        }
        ans[qu[i].id] = (current == (qu[i].r - qu[i].l + 1));
    }

    for (int i = 0; i < m; ++i) {
        if (ans[i]) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}