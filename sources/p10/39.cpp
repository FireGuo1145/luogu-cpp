// P1039 [NOIP 2003 提高组] 侦探推理
// https://www.luogu.com.cn/problem/P1039

#include<bits/stdc++.h>
int main() {
    int m, n, p;
    std::cin >> m >> n >> p;
    std::vector<std::string> names(m);
    for (int i = 0; i < m; i++) std::cin >> names[i];
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::vector<std::pair<std::string, std::string>> contents(p);
    for (int i = 0; i < p; i++) {
        std::string s;
        std::getline(std::cin, s);
        if (!s.empty() && s.back() == '\r') s.pop_back();
        size_t pos = s.find(": ");
        if (pos == std::string::npos) {
            contents[i] = {"", ""};
            continue;
        }
        contents[i] = {s.substr(0, pos), s.substr(pos + 2)};
        if (!contents[i].second.empty() && contents[i].second.back() == '.') {
            contents[i].second.pop_back();
        }
    }
    std::vector<std::string> weekdays = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    std::set<std::string> possible;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 7; j++) {
            std::vector<int> status(m, -1);
            bool valid = true;
            for (int k = 0; k < p; k++) {
                std::string speaker = contents[k].first;
                std::string s = contents[k].second;
                int person = -1;
                for (int t = 0; t < m; t++) {
                    if (names[t] == speaker) {
                        person = t;
                        break;
                    }
                }
                if (person == -1) continue;
                int truth = -1;
                if (s == "I am guilty") {
                    truth = (speaker == names[i]);
                } else if (s == "I am not guilty") {
                    truth = (speaker != names[i]);
                } else if (s.find("Today is ") == 0) {
                    truth = (s.substr(9) == weekdays[j]);
                } else if (s.find(" is not guilty") != std::string::npos) {
                    std::string target = s.substr(0, s.find(" is not guilty"));
                    truth = (target != names[i]);
                } else if (s.find(" is guilty") != std::string::npos) {
                    std::string target = s.substr(0, s.find(" is guilty"));
                    truth = (target == names[i]);
                }
                if (truth == -1) continue;
                if (status[person] != -1 && status[person] != truth) {
                    valid = false;
                    break;
                }
                status[person] = truth;
            }
            if (!valid) continue;
            int liars = 0, unknown = 0;
            for (int k = 0; k < m; k++) {
                if (status[k] == 0) liars++;
                if (status[k] == -1) unknown++;
            }
            if (liars <= n && n <= liars + unknown) {
                possible.insert(names[i]);
            }
        }
    }
    if (possible.empty()) {
        std::cout << "Impossible\n";
    } else if (possible.size() > 1) {
        std::cout << "Cannot Determine\n";
    } else {
        std::cout << *possible.begin() << '\n';
    }
    return 0;
}