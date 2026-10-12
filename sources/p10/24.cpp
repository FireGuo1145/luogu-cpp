// P1024 [NOIP 2001 提高组] 一元三次方程求解
// https://www.luogu.com.cn/problem/P1024

#include<bits/stdc++.h>

double a, b, c, d;

double get(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

int main() {
    std::cin >> a >> b >> c >> d;

    double x1 = 0, x2 = 0, x3 = 0;
    int present = -101;

    for (double i = -100; i < 100; i++) {
        double left = i, right = i + 1;

        if (std::abs(get(left)) < 1e-8) {
            x1 = left;
            present = i;
            break;
        }

        if (get(left) * get(right) < 0) {
            while (right - left > 1e-7) {
                double mid = (left + right) / 2;

                if (get(left) * get(mid) <= 0) {
                    right = mid;
                } else {
                    left = mid;
                }
            }

            x1 = (left + right) / 2;
            present = i;
            break;
        }
    }

    for (double i = present + 1; i < 100; i++) {
        double left = i, right = i + 1;

        if (std::abs(get(left)) < 1e-8) {
            if (std::abs(left - x1) < 1e-6) continue;
            x2 = left;
            present = i;
            break;
        }

        if (get(left) * get(right) < 0) {
            while (right - left > 1e-7) {
                double mid = (left + right) / 2;

                if (get(left) * get(mid) <= 0) {
                    right = mid;
                } else {
                    left = mid;
                }
            }

            x2 = (left + right) / 2;
            present = i;
            break;
        }
    }

    for (double i = present + 1; i < 100; i++) {
        double left = i, right = i + 1;

        if (std::abs(get(left)) < 1e-8) {
            if (std::abs(left - x1) < 1e-6 || std::abs(left - x2) < 1e-6) continue;
            x3 = left;
            present = i;
            break;
        }

        if (get(left) * get(right) < 0) {
            while (right - left > 1e-7) {
                double mid = (left + right) / 2;

                if (get(left) * get(mid) <= 0) {
                    right = mid;
                } else {
                    left = mid;
                }
            }

            x3 = (left + right) / 2;
            present = i;
            break;
        }
    }

    if (std::abs(get(100)) < 1e-8) {
        if (x1 == 0) {
            x1 = 100;
        } else if (x2 == 0) {
            x2 = 100;
        } else {
            x3 = 100;
        }
    }

    std::cout << std::fixed << std::setprecision(2)
              << x1 << " " << x2 << " " << x3 << "\n";

    return 0;
}