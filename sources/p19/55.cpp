// P1955 [NOI2015] 程序自动分析
// https://www.luogu.com.cn/problem/P1955

#include<bits/stdc++.h>

std::map<long long, long long> sets;
long long find(long long x) {
    if (sets.find(x) == sets.end()) sets[x] = x;
    if (sets[x] == x) return x;
    return sets[x] = find(sets[x]);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    std::vector<bool> cans(t, true);
    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::vector<std::pair<int, int>> conditions;
        sets.clear();
        for (int j = 0; j < n; j++) {
            int I, J, E;
            std::cin >> I >> J >> E;
            if (E == 1) sets[find(I)] = find(J);
            else conditions.push_back({I, J});
        }
        bool can = true;
        for (auto condition: conditions) {
            if (find(condition.first) == find(condition.second)) {
                can = false;
            }
        }
        cans[i] = can;
    }
    for (int i = 0; i < t; i++) {
        if (cans[i]) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }
    return 0;
}