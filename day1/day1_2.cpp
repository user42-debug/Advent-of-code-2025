#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("in_day1.txt");
    char dir;
    int cur = 50;
    int last = 50;
    int res = 0;
    while (fin >> dir) {
        int num;
        fin >> num;
        int step = (dir == 'R' ? 1 : -1);
        for (int i = 0; i < num; i++) {  
            cur = (cur + step + 100) % 100;
            if (cur == 0) res++;
        }
    }
    cout << res;
}