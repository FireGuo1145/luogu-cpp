// P1010 [NOIP 1998 普及组] 幂次方
// https://www.luogu.com.cn/problem/P1010

#include<bits/stdc++.h>

void get(int n) {
    bool flag = true;
    for (int i = 14; i >= 0; i--) {
        if ((n & 1 << i) == 0) {
            continue;
        }
        if (!flag) {
            std::cout << "+";
        }
        flag = false;
        if (i == 0) {
            std::cout << "2(0)";
        } else if (i == 1) {
            std::cout << "2";
        } else {
            std::cout << "2(";
            get(i);
            std::cout << ")";
        }
    }
}

int main() {
    int n;
    std::cin >> n;
    get(n);
    std::cout << std::endl;
    return 0;
}