// P1029 [NOIP 2001 普及组] 最大公约数和最小公倍数问题
// https://www.luogu.com.cn/problem/P1029

#include<bits/stdc++.h>

int main() {
    long long x0, y0, count = 0;
    std::cin >> x0 >> y0;
    int product = x0 * y0;
    for (int x = 1; x <= std::sqrt(product); x++) {
        int y = product / x;
        if (product % x != 0) continue;
        long long gcd = std::__gcd(x, y);
        if (gcd == x0) {
            if (x == y) {
                count++;
            } else {
                count += 2;
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}