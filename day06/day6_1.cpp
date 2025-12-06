#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ifstream fin("in_day6.txt");

    vector<int> mul, add;
    string cur;
    getline(fin, cur);
    while (cur[3] >= '0' && cur[3] <= '9') {
        stringstream ss(cur);
        int a, i=0;
        while (ss >> a) {
            if (i == mul.size()) {
                mul.push_back(1);
                add.push_back(0);
            }
            mul[i] *= a;
            add[i] += a;
            i++;
        }
        getline(fin, cur);
    }
    char c;
    int res = 0, i = 0;
    stringstream ss(cur);
    while (ss >> c) {
        if (c == '*') res += mul[i];
        else if (c == '+') res += add[i];
        else i--;
        i++;
    }
    cout << res;
}
