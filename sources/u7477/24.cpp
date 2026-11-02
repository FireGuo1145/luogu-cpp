// U747724 滑行机器人
// https://luogu.com.cn/problem/U747706

#include<bits/stdc++.h>

int main() {
    int n, m, x, y;
    long long k;
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
    // 找每个地方上下左右终点
    std::vector<std::vector<std::pair<int, int>>> up(n + 1, std::vector<std::pair<int, int>>(m + 1, {0, 0})), down(n + 1, std::vector<std::pair<int, int>>(m + 1, {0, 0})), left(n + 1, std::vector<std::pair<int, int>>(m + 1, {0, 0})), right(n + 1, std::vector<std::pair<int, int>>(m + 1, {0, 0}));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            up[i][j] = {i, j};
            down[i][j] = {i, j};
            left[i][j] = {i, j};
            right[i][j] = {i, j};
            if (g[i][j]) {
                continue;
            }
            while (up[i][j].first > 1 && !g[up[i][j].first - 1][up[i][j].second]) {
                up[i][j].first--;
            }
            while (down[i][j].first < n && !g[down[i][j].first + 1][down[i][j].second]) {
                down[i][j].first++;
            }
            while (left[i][j].second > 1 && !g[left[i][j].first][left[i][j].second - 1]) {
                left[i][j].second--;
            }
            while (right[i][j].second < m && !g[right[i][j].first][right[i][j].second + 1]) {
                right[i][j].second++;
            }
        }
    }
    std::unordered_map<long long, long long> vis; // 记录每个位置被访问的次数
    long long cnt = 0;
    while (cnt < k) {   // 找循环不然太慢
        long long key = 1LL * corrent_position.first * (m + 1) + corrent_position.second;
        if (vis.count(key)) {
            long long len = cnt - vis[key];
            long long loop = (k - cnt) / len;
            cnt += loop * len;
            if (cnt == k) break;
        }
        vis[key] = cnt;
        for (char c : operates) {
            if (c == 'U') {
                corrent_position = up[corrent_position.first][corrent_position.second];
            } else if (c == 'D') {
                corrent_position = down[corrent_position.first][corrent_position.second];
            } else if (c == 'L') {
                corrent_position = left[corrent_position.first][corrent_position.second];
            } else if (c == 'R') {
                corrent_position = right[corrent_position.first][corrent_position.second];
            }
        }
        cnt++;
    }
    std::cout << corrent_position.first << " " << corrent_position.second << std::endl;
    return 0;
}