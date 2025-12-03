#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> to_vec(string s) {
    vector<int> res;
    for (char i : s) {
        res.push_back(i-'0');
    }
    return res;
}

signed main() {
    ifstream fin("in_day3.txt");
    string cur;
    int res = 0;
    while (fin >> cur) {
        vector<int> range = to_vec(cur);
        vector<int> maxis = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for (int i = 0; i < range.size(); i++) {
            bool flag = false;
            for (int j = 0; j < 12; j++) {
                if (flag) maxis[j] = 0;
                else if (maxis[j] < range[i] && range.size()-i >= 12-j) {
                    flag = true;
                    maxis[j] = range[i];
                }
            }
        }
        for (int i = 0; i < 12; i++) res += maxis[i]*pow(10, 11-i);
    }
    cout << res;
}