// @Title: P3501 [POI 2010] ANT-Antisymmetry
// @Link: https://www.luogu.com.cn/problem/P3501
// @Author: FireGuo
// @Time: 2026-11-25 02:23

#include <bits/stdc++.h>

std::vector<unsigned long long> pows, left, right;

unsigned long long getleft(int l, int r) {
    return left[r] - left[l - 1] * pows[r - l + 1];
}

unsigned long long getright(int l, int r) {
    return right[l] - right[r + 1] * pows[r - l + 1];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    s = " " + s;
    auto b = s;
    for (int i = 1; i <= n; i++) {
        b[i] = (s[i] == '0' ? '1' : '0');
    }
    int themod = 13331;
    pows.resize(n + 2);
    pows[0] = 1;
    left.resize(n + 2);
    right.resize(n + 2);
    left[0] = 0;
    right[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
        pows[i] = pows[i - 1] * themod;
        left[i] = left[i - 1] * themod + s[i];
    }
    for (int i = n; i >= 1; i--) {
        right[i] = right[i + 1] * themod + b[i];
    }
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        int l = 1, r = std::min(i, n - i);
        int best = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (mid == 0 || getleft(i - mid + 1, i) == getright(i + 1, i + mid)) {
                best = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        ans += best;
    }
    std::cout << ans << std::endl;
    return 0;
}
