// B3644 【模板】拓扑排序 / 家谱树
// https://www.luogu.com.cn/problem/P3644

#include<bits/stdc++.h>

int main() {
    int n;
    std::cin >> n;
    std::vector<int> in(n + 1, 0);
    std::vector<std::vector<int>> out(n + 1);
    for (int i = 1; i <= n; i++) {
        int x;
        while (std::cin >> x && x != 0) {
            out[i].push_back(x);
            in[x]++;
        }
    }
    std::queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        std::cout << x << " ";
        for (int i : out[x]) {
            in[i]--;
            if (in[i] == 0) {
                q.push(i);
            }
        }
    }
    std::cout << std::endl;
    return 0;
}