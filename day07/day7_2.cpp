#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ifstream fin("in_day7.txt");
    string firstLine;
    getline(fin, firstLine);

    int n = firstLine.size();
    vector<int> pos(n, 0);
    for (int i = 0; i < n; i++) {
        if (firstLine[i] == 'S') pos[i] = 1;
    }
    char cur;
    int i = 0;
    while (fin >> cur) {
        if (cur == '^' && pos[i] != 0) {
            if (i > 0) pos[i-1] += pos[i];
            if (i < n-1) pos[i+1] += pos[i];
            pos[i] = 0;
        }
        i++;
        i %= n;
    }
    int res = 0;
    for (int i : pos) res += i;
    cout << res;
}
