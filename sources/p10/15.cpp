// P1015 [NOIP 1999 普及组] 回文数
// https://www.luogu.com.cn/problem/P1015

#include<bits/stdc++.h>

std::string add(std::string a, std::string b, int x) {
    std::string ans = "";
    int i = a.size() - 1, j = b.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int n1 = 0, n2 = 0;
        if (i >= 0) {
            n1 = a[i] - '0';
            if (x == 16 && n1 > 9) n1 = a[i] - 'A' + 10;
        }
        if (j >= 0) {
            n2 = b[j] - '0';
            if (x == 16 && n2 > 9) n2 = b[j] - 'A' + 10;
        }
        int sum = n1 + n2 + carry;
        if (sum >= x) {
            sum -= x;
            carry = 1;
        } else {
            carry = 0;
        }
        if (x == 16 && sum >= 10) ans += 'A' + sum - 10;
        else ans += sum + '0';
        i--;
        j--;
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    std::string m;
    int n;
    std::cin >> n >> m;
    for (int i = 1; i <= 30; i++) {
        m = add(m, std::string(m.rbegin(), m.rend()), n);
        if (m == std::string(m.rbegin(), m.rend())) {
            std::cout << "STEP=" << i << std::endl;
            return 0;
        }
    }
    std::cout << "Impossible!" << std::endl;
    return 0;
}