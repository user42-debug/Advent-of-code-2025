#include <bits/stdc++.h>
#define int long long
using namespace std;

ifstream fin("in_day10.txt");

int n;
vector<vector<int>> matrix;
vector<int> joltage;
vector<int> buttons;

int res = LLONG_MAX;

void dfs(int idx, vector<int> &current, vector<int> &curSum) {
    if (idx == buttons.size()) {
        bool ok = true;
        for (int i = 0; i < n; i++)
            if (curSum[i] != joltage[i]) ok = false;

        if (ok) {
            int s = 0;
            for (auto x : current) s += x;
            res = min(res, s);
        }
        return;
    }

    int maxPress = LLONG_MAX;
    for (int i = 0; i < n; i++) {
        if (matrix[i][idx] == 0) continue;
        maxPress = min(maxPress, joltage[i] - curSum[i]);
    }
    if (maxPress < 0) return;

    for (int k = 0; k <= maxPress; k++) {
        current[idx] = k;
        for (int i = 0; i < n; i++)
            curSum[i] += matrix[i][idx] * k;
        dfs(idx + 1, current, curSum);
        for (int i = 0; i < n; i++)
            curSum[i] -= matrix[i][idx] * k;
    }
}

signed main() {
    char c;
    int r = 0;
    while (fin >> c) {
        n = 0;
        while (fin >> c && c != ']') n++;

        buttons.clear();
        while (fin >> c && c != '{') {
            if (c == '(') {
                int cur = 0, i;
                while (true) {
                    fin >> i;
                    cur |= (1 << (n-1-i));
                    fin >> c;
                    if (c == ')') break;
                }
                buttons.push_back(cur);
            }
        }

        joltage.clear();
        while (true) {
            int i;
            fin >> i;
            joltage.push_back(i);
            fin >> c;
            if (c == '}') break;
        }
        matrix.assign(n, vector<int>(buttons.size(), 0));
        for (int j = 0; j < buttons.size(); j++) {
            int mask = buttons[j];
            for (int i = 0; i < n; i++) {
                int bit = (mask >> (n-1-i)) & 1;
                matrix[i][j] = bit;
            }
        }

        vector<int> current(buttons.size(), 0);
        vector<int> curSum(n, 0);
        res = LLONG_MAX;
        dfs(0, current, curSum);

        r += res;
    }
    cout << r;
}
