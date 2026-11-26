// @Title: P4407 [JSOI2009] 电子字典
// @Link: https://www.luogu.com.cn/problem/P4407
// @Author: FireGuo
// @Time: 2026-11-25 06:27

#include <bits/stdc++.h>

std::vector<std::string> words;
std::vector<unsigned long long> hashes;

unsigned long long count_hash(std::string &s) {
    unsigned long long hash = 0;
    for (std::size_t i = 0; i < s.size(); ++i) {
        hash = hash * 131 + s[i];
    }
    return hash;
}

unsigned long long count_left_hash(std::string &s, int i) {
    unsigned long long hash = 0;
    for (int j = 0; j < i; ++j) {
        hash = hash * 131 + s[j];
    }
    return hash;
}

unsigned long long count_right_hash(std::string &s, int i) {
    unsigned long long hash = 0;
    for (std::size_t j = i; j < s.size(); ++j) {
        hash = hash * 131 + s[j];
    }
    return hash;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    unsigned long long p[25];
    p[0] = 1;
    for (int i = 1; i < 25; ++i) {
        p[i] = p[i - 1] * 131;
    }
    int n, m;
    std::cin >> n >> m;
    words.resize(n + 1);
    hashes.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> words[i];
        hashes[i] = count_hash(words[i]);
    }
    std::sort(hashes.begin() + 1, hashes.end());
    hashes.erase(std::unique(hashes.begin() + 1, hashes.end()), hashes.end());
    std::vector<unsigned long long> canbecome;
    canbecome.reserve(1100);
    for (int i = 1; i <= m; ++i) {
        std::string query;
        std::cin >> query;
        unsigned long long query_hash = count_hash(query);
        canbecome.clear();
        for (std::size_t j = 0; j < query.size(); ++j) {
            for (char k = 'a'; k <= 'z'; ++k) {
                if (k == query[j]) continue;
                unsigned long long changed = k - query[j];
                unsigned long long new_hash = query_hash + changed * p[query.size() - j - 1];
                canbecome.push_back(new_hash);
            }
        }
        for (std::size_t j = 0; j <= query.size(); ++j) {
            unsigned long long left = count_left_hash(query, j);
            unsigned long long right = count_right_hash(query, j);
            for (char k = 'a'; k <= 'z'; ++k) {
                unsigned long long newhash = (left * 131 + k) * p[query.size() - j] + right;
                canbecome.push_back(newhash);
            }
        }
        for (std::size_t j = 0; j < query.size(); ++j) {
            unsigned long long left = count_left_hash(query, j);
            unsigned long long right = count_right_hash(query, j + 1);
            unsigned long long newhash = left * p[query.size() - j - 1] + right;
            canbecome.push_back(newhash);
        }
        std::sort(canbecome.begin(), canbecome.end());
        canbecome.erase(std::unique(canbecome.begin(), canbecome.end()), canbecome.end());
        int count = 0;
        for (auto toget : canbecome) {
            if (std::binary_search(hashes.begin() + 1, hashes.end(), toget)) ++count;
        }
        if (std::binary_search(hashes.begin() + 1, hashes.end(), query_hash)) {
            std::cout << -1 << std::endl;
            continue;
        }
        std::cout << count << std::endl;
    }
    return 0;
}