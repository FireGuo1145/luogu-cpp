// P1013 [NOIP 1998 提高组] 进制位
// https://www.luogu.com.cn/problem/P1013

#include<bits/stdc++.h>
int main() {
    int n;
    std::cin >> n;
    std::vector<std::vector<std::string>> s(n, std::vector<std::string>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> s[i][j];
        }
    }
    int jin = n - 1;
    std::map<char, int> m;
    std::map<int, char> rev;
    for (int i = 1; i < n; i++) {
        int cnt = 0;
        for (int j = 1; j < n; j++) {
            if (s[i][j].size() == 2) cnt++;
            else if (s[i][j].size() != 1) {
                std::cout << "ERROR!" << std::endl;
                return 0;
            }
        }
        char c = s[i][0][0];
        if (cnt >= jin || rev.count(cnt)) {
            std::cout << "ERROR!" << std::endl;
            return 0;
        }
        m[c] = cnt;
        rev[cnt] = c;
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            int sum = m[s[i][0][0]] + m[s[0][j][0]];
            std::string ans;
            if (sum < jin) {
                ans += rev[sum];
            } else {
                if (!rev.count(1) || !rev.count(sum - jin)) {
                    std::cout << "ERROR!" << std::endl;
                    return 0;
                }
                ans += rev[1];
                ans += rev[sum - jin];
            }
            if (s[i][j] != ans) {
                std::cout << "ERROR!" << std::endl;
                return 0;
            }
        }
    }
    for (int i = 1; i < n; i++) {
        std::cout << s[0][i] << "=" << m[s[0][i][0]];
        if (i != n - 1) std::cout << " ";
    }
    std::cout << std::endl << jin << std::endl;
    return 0;
}