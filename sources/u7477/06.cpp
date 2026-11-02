// U747706 滑行机器人
// https://luogu.com.cn/problem/U747706

#include<bits/stdc++.h>

int main() {
    int n, m, x, y, k;
    std::cin >> n >> m >> x >> y >> k;
    std::vector<std::vector<bool>> g(n + 1, std::vector<bool>(m + 1, 1)); // 0表示空地，1表示障碍物
    for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= m; j++) {
        //     char t;
        //     t = std::cin.get();
        //     if (t == '#') {
        //         g[i][j] = 1;
        //     } else {
        //         g[i][j] = 0;
        //     }
        // }
        // std::cin.get();
        std::string s;
        std::cin >> s;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == '#') {
                g[i][j + 1] = 1;
            } else {
                g[i][j + 1] = 0;
            }
        }
    }
    std::string operates;
    std::cin >> operates;
    std::pair<int, int> corrent_position = {x, y};
    for (char c : operates) {
        if (c == 'U') {
            while (corrent_position.first > 1 && !g[corrent_position.first - 1][corrent_position.second]) {
                corrent_position.first--;
            }
        } else if (c == 'D') {
            while (corrent_position.first < n && !g[corrent_position.first + 1][corrent_position.second]) {
                corrent_position.first++;
            }
        } else if (c == 'L') {
            while (corrent_position.second > 1 && !g[corrent_position.first][corrent_position.second - 1]) {
                corrent_position.second--;
            }
        } else if (c == 'R') {
            while (corrent_position.second < m && !g[corrent_position.first][corrent_position.second + 1]) {
                corrent_position.second++;
            }
        }
    }
    std::cout << corrent_position.first << " " << corrent_position.second << std::endl;
    return 0;
}