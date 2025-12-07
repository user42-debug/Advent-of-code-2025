#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ifstream fin("in_day6.txt");

    vector<string> s(5);
    vector<stringstream> ss;
    string line;
    for (int i = 0; i < 5; i++) {
        getline(fin, s[i]);
        ss.emplace_back(s[i]);
    }
    int W = 0;
    for (int i = 0; i < 4; i++) W = max(W, (int)s[i].size());
    char op;
    ss[4] >> op;
    int total = (op == '+') ? 0 : 1;
    int res = 0;

    for (int c = 0; c < W; c++) {

        if (s[0][c] == ' ' && s[1][c] == ' ' && s[2][c] == ' ' && s[3][c] == ' ') {
            ss[4] >> op;
            res += total;
            total = (op == '+') ? 0 : 1;
            continue;
        }

        string num;
        for (int r = 0; r < 4; r++)
            if (c < s[r].size() && s[r][c] != ' ') num += s[r][c];

        long long n = stoll(num);

        if (op == '+') total += n;
        else total *= n;
    }
    res += total;
    
    cout << res;
}
