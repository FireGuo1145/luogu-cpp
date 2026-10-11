// P1022 [NOIP 2000 普及组] 计算器的改良
// https://www.luogu.com.cn/problem/P1022

#include<bits/stdc++.h>
int main() {
    std::string s;
    std::getline(std::cin, s);
    std::string left = s.substr(0, s.find('='));
    std::string right = s.substr(s.find('=') + 1);
    double a = 0, b = 0; // a常数项，b未知数系数
    char x = 'x';
    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            x = c;
            break;
        }
    }
    for (int side = 0; side < 2; side++) {
        std::string str = side == 0 ? left : right;
        int sign = 1, num = 0;
        bool hasnum = false;
        for (int i = 0; i <= (int)str.size(); i++) {
            char c = i < (int)str.size() ? str[i] : '+';
            if (c >= '0' && c <= '9') {
                num = num * 10 + c - '0';
                hasnum = true;
                continue;
            }
            if (c == x) {
                b += (side == 0 ? 1 : -1) * sign * (hasnum ? num : 1);
            } else if (hasnum) {
                a += (side == 0 ? 1 : -1) * sign * num;
            }
            num = 0;
            hasnum = false;
            if (c == '-') sign = -1;
            else if (c == '+') sign = 1;
        }
    }
    double result = -a / b;
    if (result == 0) result = 0;
    std::cout << x << '=' << std::fixed << std::setprecision(3) << result << '\n';
    return 0;
}