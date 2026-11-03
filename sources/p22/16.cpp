// P2216 [HAOI2007] 理想的正方形
// https://www.luogu.com.cn/problem/P2216

#include <bits/stdc++.h>

int main() {
    int a, b, n;
    std::cin >> a >> b >> n;
    std::vector<std::vector<int>> g(a, std::vector<int>(b));
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            std::cin >> g[i][j];
        }
    }
    std::vector<std::vector<int>> mx1(a, std::vector<int>(b - n + 1)), mn1(a, std::vector<int>(b - n + 1));
    std::vector<std::vector<int>> mx2(a - n + 1, std::vector<int>(b - n + 1)), mn2(a - n + 1, std::vector<int>(b - n + 1));
    std::deque<int> q;
    for (int i = 0; i < a; i++) {
        q.clear();
        for (int j = 0; j < b; j++) {
            while (!q.empty() && g[i][q.back()] <= g[i][j]) {
                q.pop_back();
            }
            q.push_back(j);
            while (!q.empty() && q.front() <= j - n) {
                q.pop_front();
            }
            if (j >= n - 1)
                mx1[i][j - n + 1] = g[i][q.front()];
        }
        q.clear();
        for (int j = 0; j < b; j++) {
            while (!q.empty() && g[i][q.back()] >= g[i][j]) {
                q.pop_back();
            }
            q.push_back(j);
            while (!q.empty() && q.front() <= j - n) {
                q.pop_front();
            }
            if (j >= n - 1)
                mn1[i][j - n + 1] = g[i][q.front()];
        }
    }
    for (int j = 0; j < b - n + 1; j++) {
        q.clear();
        for (int i = 0; i < a; i++) {
            while (!q.empty() && mx1[q.back()][j] <= mx1[i][j]) {
                q.pop_back();
            }
            q.push_back(i);
            while (!q.empty() && q.front() <= i - n) {
                q.pop_front();
            }
            if (i >= n - 1)
                mx2[i - n + 1][j] = mx1[q.front()][j];
        }
        q.clear();
        for (int i = 0; i < a; i++) {
            while (!q.empty() && mn1[q.back()][j] >= mn1[i][j]) {
                q.pop_back();
            }
            q.push_back(i);
            while (!q.empty() && q.front() <= i - n) {
                q.pop_front();
            }
            if (i >= n - 1)
                mn2[i - n + 1][j] = mn1[q.front()][j];
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < a - n + 1; i++) {
        for (int j = 0; j < b - n + 1; j++) {
            ans = std::min(ans, mx2[i][j] - mn2[i][j]);
        }
    }
    std::cout << ans;
    return 0;
}