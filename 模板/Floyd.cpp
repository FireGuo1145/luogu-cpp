#include<bits/stdc++.h>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> distance(n + 1, std::vector<int>(n + 1, INT_MAX / 2));
    for (int i = 1; i <= n; i++) {
        distance[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        std::cin >> u >> v >> w;
        distance[u][v] = std::min(distance[u][v], w);
        distance[v][u] = std::min(distance[v][u], w);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                distance[i][j] = std::min(distance[i][j], distance[i][k] + distance[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            std::cout << distance[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}