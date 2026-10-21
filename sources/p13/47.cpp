// P1347 [ECNA 2001] 排序
// https://www.luogu.com.cn/problem/P1347

#include<bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> g(n);
    std::vector<int> in(n, 0);
    for(int i = 1; i <= m; i++) {
        std::string s;
        char a, op, b;
        std::cin >> s;
        a = s[0], op = s[1], b = s[2];
        int u = a - 'A', v = b - 'A';
        g[u].push_back(v);
        in[v]++;
        std::vector<int> into = in;
        std::queue<int> q;
        for(int j = 0; j < n; j++) {
            if(into[j] == 0) q.push(j);
        }
        std::vector<int> ans;
        bool flag = true;
        while(!q.empty()) {
            if(q.size() > 1) flag = false;
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(int v : g[u]) {
                into[v]--;
                if(into[v] == 0) q.push(v);
            }
        }
        if(ans.size() < n) {
            std::cout << "Inconsistency found after " << i << " relations." << std::endl;
            return 0;
        }
        if(flag) {
            std::cout << "Sorted sequence determined after " << i << " relations: ";
            for (int x : ans) {
                std::cout << char(x + 'A');
            }
            std::cout << '.' << std::endl;
            return 0;
        }
    }
    std::cout << "Sorted sequence cannot be determined." << std::endl;
    return 0;
}