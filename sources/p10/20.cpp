// P1020 [NOIP 1999 提高组] 导弹拦截
// https://www.luogu.com.cn/problem/P1020

#include<bits/stdc++.h>

int main() {
    std::vector<int> a;
    int temp;
    while (std::cin >> temp) a.push_back(temp);
    int need = 1;
    while (a.size() > 1) {
        int max = a[0];
        int can = 1;
        auto b = a;
        for (int i = 1; i < a.size(); i++) {
            if (a[i] <= max) {
                max = a[i];
                can = i + 1;
                b.erase(b.begin() + i);
            } else {
                continue;
            }
        }
        if (need == 1) {
            std::cout << can << std::endl;
        }
        if (!b.empty()) {
            need++;
        }
        a = b;
    }
    std::cout << need << std::endl;
    return 0;
}