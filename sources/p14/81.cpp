// @Title: P1481 魔族密码
// @Link: https://www.luogu.com.cn/problem/P1481
// @Author: FireGuo
// @Time: 2026-11-25 02:20

#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::string> words(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> words[i];
    }
    std::sort(words.begin() + 1, words.end(), [](const std::string &a, const std::string &b){
        return a.size() < b.size();
    });
    int max = 1;
    std::vector<int> dp(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j < i; ++j) {
            if (words[i].find(words[j]) == 0) {
                dp[i] = std::max(dp[i], dp[j] + 1);
            }
        }
        max = std::max(max, dp[i]);
    }
    std::cout << max << std::endl;
    return 0;
}
