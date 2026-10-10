// P1011 [NOIP 1998 提高组] 车站
// https://www.luogu.com.cn/problem/P1011

#include<bits/stdc++.h>

int addat(int t) {
    if (t == 1) return 1;
    if (t == 2) return 0;
    return addat(t - 1) + addat(t - 2);
}

int addyt(int t) {
    if (t == 1) return 0;
    if (t == 2) return 1;
    return addyt(t - 1) + addyt(t - 2);
}

int delat(int t) {
    if (t == 1) return 0;
    if (t == 2) return 0;
    if (t == 3) return 0;
    return addat(t - 1);
}

int delyt(int t) {
    if (t == 1) return 0;
    if (t == 2) return 1;
    return addyt(t - 1);
}

int getat(int t) {
    return addat(t) - delat(t);
}

int getyt(int t) {
    return addyt(t) - delyt(t);
}

int sumat(int t) {
    int sum = 0;
    for (int i = 1; i <= t; i++) {
        sum += getat(i);
    }
    return sum;
}

int sumyt(int t) {
    int sum = 0;
    for (int i = 1; i <= t; i++) {
        sum += getyt(i);
    }
    return sum;
}

int main() {
    // std::cout << sumyt(5) << std::endl;
    int a, n, m, x;
    std::cin >> a >> n >> m >> x;
    if (x == n) {
        std::cout << a << std::endl;
        return 0;
    }
    if (n == 2) {
        std::cout << m << std::endl;
        return 0;
    }
    int y = (m - sumat(n - 1) * a) / (sumyt(n - 1));
    int xn = sumyt(x) * y + sumat(x) * a;
    std::cout << xn << std::endl;
    return 0;
}