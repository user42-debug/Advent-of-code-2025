#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ifstream fin("in_day10.txt");

    int res = 0;

    char c;
    while (fin >> c) {
        int mask = 0;
        int n = 0;
        while (fin >> c && c != ']') {
            mask <<= 1;
            n++;
            if (c == '#') mask |= 1;
        }
        vector<int> buttons;
        while (fin >> c && c != '{') {
            if (c == '(') {
                int cur = 0;
                int i;
                while (true) {
                    fin >> i;
                    cur |= (1<<(n-1-i));
                    fin >> c;
                    if (c == ')') break;
                }
                buttons.push_back(cur);
            }
        }
        while (fin >> c && c != '}');

        set<int> visited;
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited.insert(0);
        bool found = false;
        if (mask == 0) continue;
        while (!q.empty() && !found) {
            int number = q.front().second, moves = q.front().first;
            q.pop();
            for (int i : buttons) {
                int val = number ^ i;
                if (visited.find(val) == visited.end()) {
                    if (val == mask) {
                        found = true;
                        res += moves+1;
                    }
                    visited.insert(val);
                    q.push(make_pair(moves+1, val));
                }
            }
        }
    }
    cout << res;
}