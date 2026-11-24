#include <bits/stdc++.h>

long long count_hash(std::string &s) {
    long long hash = 0;
    for (std::size_t i = 0; i < s.size(); ++i) {
        hash = (hash * 131 + s[i]) % 1000000007;
    }
    return hash;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<long long> hashs;
    for (int i = 0; i < n; ++i) {
        std::string s;
        std::cin >> s;
        hashs.push_back(count_hash(s));
    }
    std::sort(hashs.begin(), hashs.end());
    auto it = std::unique(hashs.begin(), hashs.end());
    std::cout << (it - hashs.begin()) << std::endl;
    return 0;
}
