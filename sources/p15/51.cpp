// P1551 亲戚
// https://www.luogu.com.cn/problem/P1551

#include<bits/stdc++.h>

std::vector<int> sets(1000000);
int find(int x) {
    if (sets[x] == x) return x;
    else return sets[x] = find(sets[x]);
}

int main() {
    int n, m, p;
    std::cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) sets[i] = i;
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        sets[find(a)] = find(b);
    }
    for (int i = 0; i < p; i++) {
        int a, b;
        std::cin >> a >> b;
        if (find(a) == find(b)) std::cout << "Yes" << std::endl;
        else std::cout << "No" << std::endl;
    }
    return 0;
}