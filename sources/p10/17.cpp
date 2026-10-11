// P1017 [NOIP 2000 提高组] 进制转换
// https://www.luogu.com.cn/problem/P1017

#include<bits/stdc++.h>

int main() {
    int n, r;   // r进制（负的），n为十进制数
    std::cin >> n >> r;
    std::stack<char> stk;   // 栈
    bool flag = true;
    int remain = n;
    while (remain != 0) {
        int temp = remain % r;
        remain /= r;
        if (temp < 0) {
            temp -= r;
            remain++;
        }
        if (temp < 10) stk.push(temp + '0');
        else stk.push(temp - 10 + 'A');
    }
    std::string sum = "";
    while (!stk.empty()) {
        sum += stk.top();
        stk.pop();
    }
    std::cout << n << "=" << sum << "(base" << r << ")" << std::endl;
    return 0;
}