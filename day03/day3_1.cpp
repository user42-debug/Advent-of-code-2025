#include <bits/stdc++.h>
using namespace std;

vector<int> to_vec(string s) {
    vector<int> res;
    for (char i : s) {
        res.push_back(i-'0');
    }
    return res;
}

int main() {
    ifstream fin("in_day3.txt");
    string cur;
    int res = 0;
    while (fin >> cur) {
        vector<int> range = to_vec(cur);
        int maxi = 0, secM = 0;
        for (int i = 0; i < range.size(); i++) {
            if (range[i] > maxi && i < range.size()-1) {
                maxi = range[i];
                secM = 0;
            }
            else if (range[i] > secM) secM = range[i];
        }
        res += maxi*10+secM;
    }
    cout << res;
}