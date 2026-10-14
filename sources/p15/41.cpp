// P1541 [NOIP 2010 提高组] 乌龟棋
// https://www.luogu.com.cn/problem/P1541

#include<bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n + 1, 0), b(m + 1, 0);
    for (int i = 1; i <= n; i++) {
    	std::cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
    	std::cin >> b[i];
    }
    std::vector<int> cnt(5, 0);
    for (int i = 1; i <= m; i++) {
    	cnt[b[i]]++;
    }
    std::vector<std::vector<std::vector<std::vector<int>>>> dp(cnt[1]+1,std::vector<std::vector<std::vector<int>>>(cnt[2]+1,std::vector<std::vector<int>>(cnt[3]+1,std::vector<int>(cnt[4]+1,0))));
    for (int A = 0; A <= cnt[1]; A++) {
    	for (int B = 0; B <= cnt[2]; B++) {
    		for (int C = 0; C <= cnt[3]; C++) {
    			for (int D = 0; B <= cnt[4]; D++) {
                    int a1 = A > 0 ? dp[A-1][B][C][D] : 0;
                    int a2 = B > 0 ? dp[A][B-1][C][D] : 0;
                    int a3 = C > 0 ? dp[A][B][C-1][D] : 0;
                    int a4 = D > 0 ? dp[A][B][C][D-1] : 0;
    				dp[A][B][C][D] = std::max({dp[A][B][C][D], a1, a2, a3, a4}) + a[A+B+C+D+1];
    			}
    		}
    	}
    }
    std::cout << dp[cnt[1]][cnt[2]][cnt[3]][cnt[4]] << std::endl;
}