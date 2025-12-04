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
    vector<vector<int>> neighbours(grid.size(), vector<int>(grid[0].size(), 0));
    queue<pair<int, int>> q;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            int nb = 0;
            if (grid[i][j] == '.') continue;
            for (int ind = 0; ind < 8; ind++) {
                if (dx[ind]+i >= 0 && dx[ind]+i < grid.size() && dy[ind]+j >= 0 && dy[ind]+j < grid[0].size()) {
                    if (grid[i+dx[ind]][j+dy[ind]] == '@') nb++;
                }
            }
            neighbours[i][j] = nb;
            if (nb < 4) q.push(make_pair(i, j));
        }
    }
    while (!q.empty()) {
        pair<int, int> c = q.front();
        int x = c.first, y = c.second;
        q.pop();
        res++;
        for (int ind = 0; ind < 8; ind++) {
            if (dx[ind]+x >= 0 && dx[ind]+x < grid.size() && dy[ind]+y >= 0 && dy[ind]+y < grid[0].size()) {
                if (grid[x+dx[ind]][y+dy[ind]] == '@') {
                    neighbours[x+dx[ind]][y+dy[ind]]--;
                    if (neighbours[x+dx[ind]][y+dy[ind]] == 3) q.push(make_pair(x+dx[ind], y+dy[ind]));
                }
            }
        }
    }
    cout << res;
}