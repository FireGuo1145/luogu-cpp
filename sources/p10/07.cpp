// P1007 独木桥
// https://www.luogu.com.cn/problem/P1007

#include<bits/stdc++.h>

int main() {
    int l, n;
    std::cin >> l >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    int max = 0, min = 0;
    for (int i = 0; i < n; i++) {
        int max1 = std::max(a[i], (l - a[i] + 1));
        int min1 = std::min(a[i], (l - a[i] + 1));
        max = std::max(max1, max);
        min = std::max(min1, min);
    }
    std::cout << min << " "<< max << std::endl;
    return 0;
}