// P1012 [NOIP 1998 提高组] 拼数
// https://www.luogu.com.cn/problem/P1012

#include<bits/stdc++.h>

bool compare(int a, int b) {
    std::string s1 = std::to_string(a), s2 = std::to_string(b);
    return s1 + s2 > s2 + s1;
}

int main() {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    std::sort(a.begin(), a.end(), compare);
    for (int i = 0; i < n; i++) std::cout << a[i];
    std::cout << std::endl;
    return 0;
}