// U747725 隐藏二进制序列
// https://www.luogu.com.cn/problem/U747725

#include<bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::deque<int> q;
    q.push_back(1);
    int isone = -1, iszero = -1;
    for (int i = 1; i < n; i++) {
        if (isone == -1) {
            std::cout << "? " << i << " " << i + 1 << std::endl;
            std::string s;
            std::cin >> s;
            if (s == "<") {
                iszero = i;
                isone = i + 1;
                q.push_back(i + 1);
            } else {
                q.push_front(i + 1);
            }
        } else {
            std::cout << "? " << iszero << " " << i + 1 << std::endl;
            std::string s;
            std::cin >> s;
            if (s == "<") {
                q.push_back(i + 1);
            } else {
                q.push_front(i + 1);
            }
        }
    }
    std::cout << "! ";
    for (int i = 1; i <= n; i++) {
        std::cout << q[i - 1] << " ";
    }
    std::cout << std::endl;
    return 0;
}