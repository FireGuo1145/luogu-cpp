// P1009 [NOIP 1998 普及组] 阶乘之和
// https://www.luogu.com.cn/problem/P1009

#include<bits/stdc++.h>

class highprecision {
public:
    std::vector<int> num;
    highprecision() : num{0} {}
    highprecision(int n) {
        num.clear();
        if (n == 0) {
            num.push_back(0);
            return;
        }
        while (n > 0) {
            num.push_back(n % 10);
            n /= 10;
        }
    }
    highprecision& operator+=(const highprecision& b) {
        int carry = 0;
        for (int i = 0; i < num.size() || i < b.num.size() || carry; i++) {
            if (i == num.size()) num.push_back(0);
            num[i] += carry;
            if (i < b.num.size()) num[i] += b.num[i];
            carry = num[i] / 10;
            num[i] %= 10;
        }
        return *this;
    }
    highprecision& operator+=(int b) {
        return *this += highprecision(b);
    }
    highprecision operator+(const highprecision& b) const {
        highprecision c = *this;
        c += b;
        return c;
    }
    highprecision& operator*=(const highprecision& b) {
        highprecision c;
        c.num.assign(num.size() + b.num.size(), 0);
        for (int i = 0; i < num.size(); i++) {
            int carry = 0;
            for (int j = 0; j < b.num.size() || carry; j++) {
                int cur = c.num[i + j] + carry;
                if (j < b.num.size()) cur += num[i] * b.num[j];
                c.num[i + j] = cur % 10;
                carry = cur / 10;
            }
        }
        while (c.num.size() > 1 && c.num.back() == 0) c.num.pop_back();
        *this = c;
        return *this;
    }
    highprecision& operator*=(int b) {
        return *this *= highprecision(b);
    }
    highprecision operator*(const highprecision& b) const {
        highprecision c = *this;
        c *= b;
        return c;
    }
    friend std::ostream& operator<<(std::ostream& out, const highprecision& b) {
        for (int i = static_cast<int>(b.num.size()) - 1; i >= 0; i--) out << b.num[i];
        return out;
    }
};

highprecision factorial(int n) {
    highprecision ans(1);
    for (int i = 1; i <= n; i++) ans *= i;
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    highprecision sum;
    for (int i = 1; i <= n; i++) {
        sum += factorial(i);
    }
    std::cout << sum << std::endl;
    return 0;
}