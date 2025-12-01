#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("in_day1.txt");
    char dir;
    int cur = 50;
    int res = 0;
    while (fin >> dir) {
        int num;
        fin >> num;
        if (dir == 'R') cur += num;
        else cur -= num;
        while (cur < 0) cur = 100+cur;
        while (cur > 99) cur = cur-100;
        if (cur == 0) res++;
    }
    cout << res;
}