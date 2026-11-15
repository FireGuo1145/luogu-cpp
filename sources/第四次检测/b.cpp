// B. 长街灯未眠

#include <bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> a[i];
    }
    int current = a[1];
    int ans = 0;
    for (int i = 2; i <= n; ++i) {
        if (a[i] != current) {
            ++ans;
            current = a[i];
        }
    }
    if (current != 0) {
        ++ans;
    }
    std::cout << ans << std::endl;
    return 0;
}