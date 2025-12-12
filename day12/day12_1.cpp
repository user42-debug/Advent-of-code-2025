#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ifstream fin("in_day12.txt");
    vector<int> shapes;
    for (int i = 0;  i < 6; i++) {
        fin.ignore();
        fin.ignore();
        char c;
        int nb = 0;
        for (int j = 0; j < 9; j++) {
            fin >> c;
            if (c == '#') nb++;
        }
        shapes.push_back(nb);
        fin.ignore();
        fin.ignore();
    }
    string s;
    int res = 0;
    while (getline(fin, s)) {
        stringstream ss(s);
        int x, y;
        char _;
        ss >> x >> _ >> y;
        ss >> _ >> _;
        int area = x*y;
        int nb = (x/3)*(y/3);
        for (int i = 0; i < 6; i++) {
            int n;
            ss >> n;
            nb -= n;
        }
        if (nb >= 0) res++;
    }
    cout << res;
}