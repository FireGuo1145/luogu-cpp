// P1003 [NOIP 2011 提高组] 铺地毯
// https://www.luogu.com.cn/problem/P1003
// By FireGuo

#include<bits/stdc++.h>

int main() {
    int n, x, y;
    std::cin >> n;
    std::vector<std::pair<int, int>> square(n), location(n);
    for (int i = 0; i < n; i++) {
        int a, b, c, d;
        std::cin >> a >> b >> c >> d;
        location[i] = std::make_pair(a, b);
        square[i] = std::make_pair(c, d);
    }
    std::cin >> x >> y;
    int result = -1;
    for (int i = 0; i < n; i++) {
        if (x >= location[i].first && x <= location[i].first + square[i].first &&
            y >= location[i].second && y <= location[i].second + square[i].second) {
            result = i + 1;
    }
    }
    std::cout << result << std::endl;
    return 0;
}