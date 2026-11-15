// D. 寄往彼岸的星语

#include <bits/stdc++.h>

int main() {
    int type, n, x;
    std::string a, b;
    std::cin >> type;
    if (type == 1) {
        std::cin >> n >> a;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == '1') {
                result ^= (i + 1);
            }
        }
        std::cout << result << std::endl;
    } else {
        std::cin >> n >> b >> x;
        int result = 0;
        for (int i = 0; i < n; ++i) {
            if (b[i] == '1') {
                result ^= (i + 1);
            }
        }
        result ^= x;
        if (result != 0) {
            b[result - 1] ^= 1;
        }
        std::cout << b << std::endl;
    }
}