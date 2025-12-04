#include <bits/stdc++.h>
using namespace std;

int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, -1, 1, 0};

int main() {
    ifstream fin("in_day4.txt");
    vector<string> grid;
    string cur;
    while (fin >> cur) grid.push_back(cur);
    int res = 0;

    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            int nb = 0;
            if (grid[i][j] == '.') continue;
            for (int ind = 0; ind < 8; ind++) {
                if (dx[ind]+i >= 0 && dx[ind]+i < grid.size() && dy[ind]+j >= 0 && dy[ind]+j < grid[0].size()) {
                    if (grid[i+dx[ind]][j+dy[ind]] == '@') nb++;
                }
            }
            if (nb < 4) res++;
        }
    }
    cout << res;
}