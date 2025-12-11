#include <bits/stdc++.h>
#define int long long
using namespace std;

unordered_map<string, vector<string>> graph;

unordered_map<string, int> visited;

int dfs(string node) {
    if (node == "out") {
        visited["out"] = 1;
        return 1;
    }
    if (visited.find(node) != visited.end()) return visited[node];
    int res = 0;
    for (string c : graph[node]) {
        res += dfs(c);
    }
    visited[node] = res;
    return res;
}

signed main() {
    ifstream fin("in_day11.txt");
    string cur;
    while (getline(fin, cur)) {
        stringstream ss(cur);
        string name = "";
        char c;
        while (ss >> c && c != ':') name += c;
        graph[name] = {};
        string to_n;
        while (ss >> to_n) graph[name].push_back(to_n);
    }

    cout << dfs("you");
}