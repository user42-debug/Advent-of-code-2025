#include <bits/stdc++.h>
#define int long long
using namespace std;

int digits(int n) {
    int d = 0;
    while (n) n /= 10, d++;
    return d;
}

int repeat_half(int a, int times) {
    int d = digits(a);
    int mul = 1;
    int res = 0;
    for (int i = 0; i < d; i++) mul *= 10;
    for (int i = 0; i < times; i++) {
        res = res * mul + a;
    }

    return res;
}

signed main() {
    ifstream fin("in_day2.txt");
    int first, id, res = 0;
    bool is_first = true;
    char _;
    set<int> false_ids_s;
    for (int i = 1; i < 1e6; i++) {
        int d = digits(i);
        for (int j = 2; j*d < 11; j++) {
            false_ids_s.insert(repeat_half(i, j));
        }
    }
    vector<int> false_ids(false_ids_s.begin(), false_ids_s.end());

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
