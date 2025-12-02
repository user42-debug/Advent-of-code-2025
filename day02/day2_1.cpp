#include <bits/stdc++.h>
#define int long long
using namespace std;

int digits(int n) {
    int d = 0;
    while (n) n /= 10, d++;
    return d;
}

int double_half(int a) {
    int d = digits(a);
    int mul = 1;
    for (int i = 0; i < d; i++) mul *= 10;
    return a * mul + a;
}

signed main() {
    ifstream fin("in_day2.txt");
    int first, id, res = 0;
    bool is_first = true;
    char _;
    vector<int> false_ids;
    for (int i = 1; i < 1e6; i++) {
        false_ids.push_back(double_half(i));
    }
    while (fin >> id) {
        fin >> _;
        if (is_first) first = id;
        else {
            int beg = lower_bound(false_ids.begin(), false_ids.end(), first) - false_ids.begin();
            for (int i = beg; false_ids[i] <= id; i++) {
                res += false_ids[i];
            }
        }
        is_first ^= 1;
    }
    cout << res;
}
