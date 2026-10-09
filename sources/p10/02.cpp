// P1002 [NOIP 2002 普及组] 过河卒
// https://www.luogu.com.cn/problem/P1002

#include<bits/stdc++.h>

int main() {
    long long bx, by, cx, cy;
    std::cin >> bx >> by >> cx >> cy;
    std::vector<std::vector<long long>> maybe(bx + 1, std::vector<long long>(by + 1, 0));
    maybe[0][0] = 1;
    for (int i = 0; i < bx + 1; i++) {
        for (int j = 0; j < by + 1; j++) {
            if ((std::abs(i - cx) == 2 && std::abs(j - cy) == 1) || (std::abs(i - cx) == 1 && std::abs(j - cy) == 2)) {
                maybe[i][j] = 0;
            } else if (i == cx && j == cy) {
                maybe[i][j] = 0;
            } else if (i == 0 && j == 0) {
                maybe[i][j] = 1;
            } else if (i == 0) {
                maybe[i][j] = maybe[i][j - 1];
            } else if (j == 0) {
                maybe[i][j] = maybe[i - 1][j];
            } else {
                maybe[i][j] = maybe[i - 1][j] + maybe[i][j - 1];
            }
        }
    }
    std::cout << maybe[bx][by] << std::endl;
    return 0;
}