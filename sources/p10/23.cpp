// P1023 [NOIP 2000 普及组] 税收与补贴问题
// https://www.luogu.com.cn/problem/P1023

#include<bits/stdc++.h>

int main() {
    int expect, cost, volume;
    std::cin >> expect >> cost >> volume;
    std::vector<std::pair<int, int>> prices;
    for (;;) {
        int price, num;
        std::cin >> price >> num;
        if (price == -1 && num == -1) break;
        prices.push_back({price, num});
    }
    int unit;
    std::cin >> unit;
    std::sort(prices.begin(), prices.end(), [](const auto &a, const auto &b) { return a.first < b.first; });
    std::vector<std::pair<int, int>> prices1;
    for (int i = 0; i < prices.size(); ++i) {
        
    }
    return 0;
}