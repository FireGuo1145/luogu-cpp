// P1014 [NOIP 1999 普及组] Cantor 表
// https://www.luogu.com.cn/problem/P1014

#include<bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    bool flag = true;
    int times = 0;
    while (flag) {
        if (n - times - 1 <= 0) {
            flag = false;
        } else {
            times++;
            n -= times;
        }
    }
    int a, b;
    if (times % 2 == 0) {
        a = times + 2 - n;
        b = n;
    } else {
        a = n;
        b = times + 2 - n;
    }
    std::cout << a << "/" << b << std::endl;
    return 0;
}