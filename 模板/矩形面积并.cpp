#include <bits/stdc++.h>

int n, m;
std::vector<long long> x, y, ey1, ey2, type, cover, len;// x: 扫描线的横坐标，y: 离散化后的纵坐标，ey1, ey2: 矩形的纵坐标，type: 扫描线的类型，cover: 线段树的覆盖数，len: 线段树的长度
std::vector<int> id1, id2, ord;

// 向上传，更新当前节点的长度信息
void pushup(int p, int l, int r) {
    if (cover[p] > 0) len[p] = y[r + 1] - y[l];
    else if (l == r) len[p] = 0;
    else len[p] = len[p * 2] + len[p * 2 + 1];
}
// 区间修改，增加或减少覆盖数
// 每个矩形一般有多个小区间组成，然后的话就需要这些区间分别给加上或者减少覆盖的数量
void update(int p, int l, int r, int ql, int qr, int v) {
    if (ql <= l && r <= qr) {// 刚好覆盖完的情况，就全部加，向上推
        cover[p] += v;
        pushup(p, l, r);
        return;
    }
    int mid = (l + r) / 2;
    if (ql <= mid) update(p * 2, l, mid, ql, qr, v);// 往下推
    if (qr > mid) update(p * 2 + 1, mid + 1, r, ql, qr, v);
    pushup(p, l, r);
}
int main() {
    std::cin >> n;
    int tot = n * 2;
    x.resize(tot + 1);
    y.resize(tot + 1);
    ey1.resize(tot + 1);
    ey2.resize(tot + 1);
    type.resize(tot + 1);
    id1.resize(tot + 1);
    id2.resize(tot + 1);
    ord.resize(tot + 1);
    for (int i = 1; i <= n; i++) {
        long long x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        int a = i * 2 - 1, b = i * 2;
        x[a] = x1;
        ey1[a] = y1;
        ey2[a] = y2;
        type[a] = 1;
        x[b] = x2;
        ey1[b] = y1;
        ey2[b] = y2;
        type[b] = -1;
        y[a] = y1;
        y[b] = y2;
    }
    std::sort(y.begin() + 1, y.end());
    y.erase(std::unique(y.begin() + 1, y.end()), y.end());// 去重
    m = y.size() - 1;
    for (int i = 1; i <= tot; i++) {
        id1[i] = std::lower_bound(y.begin() + 1, y.end(), ey1[i]) - y.begin();
        id2[i] = std::lower_bound(y.begin() + 1, y.end(), ey2[i]) - y.begin();
        ord[i] = i;
    }
    std::sort(ord.begin() + 1, ord.end(), [](int a, int b) {
        return x[a] < x[b];
    });
    cover.resize(m * 4 + 8);
    len.resize(m * 4 + 8);
    long long ans = 0;
    long long lastX = x[ord[1]];// 上次扫描的横坐标
    for (int i = 1; i <= tot; ) {
        long long nowX = x[ord[i]];// 这回横坐标，用来算这一快的面积
        ans += len[1] * (nowX - lastX);
        while (i <= tot && x[ord[i]] == nowX) {
            int k = ord[i];
            update(1, 1, m - 1, id1[k], id2[k] - 1, type[k]);// 更新一下覆盖点
            i++;
        }
        lastX = nowX;
    }
    std::cout << ans << std::endl;
    return 0;
}