// P1008 [NOIP 1998 普及组] 三连击
// https://www.luogu.com.cn/problem/P1008

#include<bits/stdc++.h>

int main() {
    for (int a = 1; a <= 3; a++) {
        for (int b = 1; b <= 9; b++) {
            for (int c = 1; c <= 9; c++) {
                int num1 = a * 100 + b * 10 + c;
                int num2 = 2 * num1;
                int a2 = num2 / 100, b2 = num2 / 10 % 10, c2 = num2 % 10;
                int num3 = 3 * num1;
                int a3 = num3 / 100, b3 = num3 / 10 % 10, c3 = num3 % 10;
                if (num3 > 999) continue;
                std::vector<bool> have(10, false);
                have[a] = true;
                have[b] = true;
                have[c] = true;
                have[a2] = true;
                have[b2] = true;
                have[c2] = true;
                have[a3] = true;
                have[b3] = true;
                have[c3] = true;
                if (have[1] && have[2] && have[3] && have[4] && have[5] && have[6] && have[7] && have[8] && have[9]) {
                    std::cout << num1 << " " << num2 << " " << num3 << std::endl;
                }
            }
        }
    }
    return 0;
}