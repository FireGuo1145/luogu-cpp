// @Title: P16522 自破碎的天空坠落
// @Link: https://www.luogu.com.cn/problem/P16522
// @Author: FireGuo
// @Time: 2026-11-16 16:03

#include <bits/stdc++.h>

struct Point {
    int x, y;
    bool operator==(const Point &other) const {
        return x == other.x && y == other.y;
    }
};

struct Edge {
    int k, b;
    bool operator==(const Edge &other) const {
        return k == other.k && b == other.b;
    }
};

struct HashPoint {
    size_t operator()(const Point &p) const {
        return (size_t)p.x ^ ((size_t)p.y << 1);
    }
};

struct HashEdge {
    size_t operator()(const Edge &e) const {
        return (size_t)e.k ^ ((size_t)e.b << 1);
    }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, q;
    std::cin >> n;
    int s = 200;
    std::unordered_map<Edge, int, HashEdge> smallklines;
    std::unordered_map<Point, int, HashPoint> bigkpoints;
    std::vector<int> smallks;
    
    for (int i = 0; i < n; ++i) {
        Edge e;
        std::cin >> e.k >> e.b;
        if (std::abs(e.k) <= s) {
            smallklines[e]++;
            if (std::find(smallks.begin(), smallks.end(), e.k) == smallks.end()) {
                smallks.push_back(e.k);
            }
        } else {
            int l = (-20000 - e.b) / e.k;
            int r = (20000 - e.b) / e.k;
            if (l > r) std::swap(l, r);
            for (int j = l; j <= r; ++j) {
                Point p;
                p.x = j;
                p.y = e.k * j + e.b;
                bigkpoints[p]++;
            }
        }
    }
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        Point p;
        std::cin >> p.x >> p.y;
        int ans = 0; 
        for (auto &k : smallks) {
            Edge e;
            e.k = k;
            e.b = p.y - k * p.x;
            if (smallklines.find(e) != smallklines.end()) {
                ans += smallklines[e];
            }
        }
        if (bigkpoints.find(p) != bigkpoints.end()) {
            ans += bigkpoints[p];
        }
        std::cout << ans << std::endl;
    }
    return 0;
}