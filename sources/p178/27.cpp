// P17827 [CSP-J 2026] 旅游 / travel（民间数据）
// https://www.luogu.com.cn/problem/P17827

#include<bits/stdc++.h>

int pos(char c){
    if (c >= 'A' && c <= 'C') return c - 'A';
    if (c == 'D') return 0;
    return 1;
}

int main(){
    std::string c1, s1, c2, s2;
    std::cin >> c1 >> s1 >> c2 >> s2;
    bool a = c1 == c2;
    bool b = a && s1.substr(0, 2) == s2.substr(0, 2);
    char x = s1[2], y = s2[2];
    bool left = (x >= 'A' && x <= 'C') && (y >= 'A' && y <= 'C');
    bool right = (x == 'D' || x == 'F') && (y == 'D' || y == 'F');
    bool c = b && (left || right);
    std::vector<int> p = {0, 1, 2, 0, 1};
    bool d = c && std::abs(pos(x) - pos(y)) == 1;
    std::cout << a << b << c << d << std::endl;
    return 0;
}