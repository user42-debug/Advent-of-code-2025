#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ifstream fin("in_day9.txt");

    vector<pair<int, int>> coords;
    int x, maxi = 0;
    char _;
    while (fin >> x) {
        int y;
        fin >> _ >> y;
        for (auto p : coords) {
            maxi = max(maxi, (abs(p.first-x)+1)*(abs(p.second-y)+1));
        }
        coords.emplace_back(x, y);
    }
    cout << maxi;
    bitset<100000> b;
}