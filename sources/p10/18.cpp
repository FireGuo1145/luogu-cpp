// P1018 [NOIP 2000 提高组] 乘积最大
// https://www.luogu.com.cn/problem/P1018

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

int main() {
    int n, k;
    std::cin >> n >> k;
    std::string s;
    std::cin >> s;
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));
    std::vector<int> nums(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        nums[i] = std::stoi(s.substr(i - 1, 1));
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = std::stoi(s.substr(0, i));
    }
    for (int i = 1; i <= n; i++) {
        // 计算dp[i][]
        for (int j = 1; j <= k && j < i; j++) {
            // 计算dp[i][j]
            for (int l = j; l < i; l++) {
                // p是最后一个乘号位置
                dp[i][j] = std::max(dp[i][j], dp[l][j - 1] * std::stoi(s.substr(l, i - l)));
            }
        }
    }
    std::cout << dp[n][k] << std::endl;
    return 0;
}