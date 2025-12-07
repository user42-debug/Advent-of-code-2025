#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("in_day7.txt");
    string firstLine;
    getline(fin, firstLine);

    int n = firstLine.size();
    set<int> pos;
    for (int i = 0; i < n; i++) {
        if (firstLine[i] == 'S') pos.insert(i);
    }
    char cur;
    int i = 0;
    int res = 0;
    while (fin >> cur) {
        if (cur == '^' && pos.find(i) != pos.end()) {
            pos.erase(i);
            pos.insert(i-1);
            pos.insert(i+1);
            res++;
        }
        i++;
        i %= n;
    }
    cout << res;
}
