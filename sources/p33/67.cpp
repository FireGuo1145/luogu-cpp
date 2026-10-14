// P3367 【模板】并查集
// https://www.luogu.com.cn/problem/P3367

#include<bits/stdc++.h>

std::vector<int> sets(1000000);
int find(int x) {
    if (sets[x] == x) return x;
    else return sets[x] = find(sets[x]);
}

int main() {
    int N, M;
    std::cin >> N >> M;
    for (int i = 1; i <= N; i++) sets[i] = i;
    for (int i = 0; i < M; i++) {
        int z, x, y;
        std::cin >> z >> x >> y;
        if (z == 1) {
            sets[find(x)] = find(y);
        } else {
            char c = (find(x) == find(y)) ? 'Y' : 'N';
            std::cout << c << std::endl;
        }
    }
    return 0;
}