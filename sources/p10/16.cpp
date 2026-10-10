// P1016 [NOIP 1999 普及组/提高组] 旅行家的预算
// https://www.luogu.com.cn/problem/P1016

#include<bits/stdc++.h>

struct station {
    double d, p;   // D 距离，P 油价
};

int main() {
    double s, c, l, p0;
    int n;
    std::cin >> s >> c >> l >> p0 >> n;
    std::vector<station> stations(n + 2);
    stations[0].d = 0;
    stations[0].p = p0;
    stations[n + 1].d = s;
    stations[n + 1].p = 0;
    for (int i = 1; i <= n; i++) {
        std::cin >> stations[i].d >> stations[i].p;
    }
    std::sort(stations.begin(), stations.end(), [](station a, station b) { return a.d < b.d; });
    double dmax = c * l;
    bool flag = true;
    int now = 0;
    double cost = 0;
    double oil = 0;
    while (flag) {
        std::vector<int> cango;
        for (int i = now + 1; i <= n + 1; i++) {
            if (stations[i].d - stations[now].d <= dmax + 1e-9) {
                cango.push_back(i);
            } else {
                break;
            }
        }
        if (cango.empty()) {
            std::cout << "No Solution" << std::endl;
            return 0;
        }
        int togo = 0;
        for (int i = 0; i < cango.size(); i++) {
            if (stations[cango[i]].p < stations[now].p) {
                togo = cango[i];
                double need = (stations[togo].d - stations[now].d) / l;
                if (oil < need) {
                    cost += ((stations[togo].d - stations[now].d) / l - oil) * stations[now].p;
                    oil = 0;
                    break;
                } else {
                    oil -= need;
                    break;
                }
            }
        }
        if (togo == 0) {
            togo = cango[0];
            for (int i = 1; i < cango.size(); i++) {
                if (stations[cango[i]].p < stations[togo].p) {
                    togo = cango[i];
                }
            }
            cost += (c - oil) * stations[now].p;
            oil = c;
            oil = oil - (stations[togo].d - stations[now].d) / l;
        }
        if (togo == n + 1) {
            flag = false;
        }
        now = togo;
    }
    std::cout << std::fixed << std::setprecision(2) << cost << std::endl;
    return 0;
}