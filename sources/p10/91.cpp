// P1091 [NOIP 2004 提高组] 合唱队形
// https://www.luogu.com.cn/problem/P1091

#include<bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> t(n + 1), left(n + 1), right(n + 1);
    for (int i = 1; i <= n; i++) std::cin >> t[i];
    for (int i = 1; i <= n; i++) {
        left[i] = 1;
        for (int j = 1; j < i; j++) {
            if (t[i] > t[j]) left[i] = std::max(left[i], left[j] + 1);
        }
    }
    for (int i = n; i >= 1; i--) {
        right[i] = 1;
        for (int j = n; j > i; j--) {
            if (t[i] > t[j]) right[i] = std::max(right[i], right[j] + 1);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = std::max(ans, left[i] + right[i] - 1);
    std::cout << n - ans << std::endl;
    return 0;
}