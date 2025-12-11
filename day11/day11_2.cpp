#include <bits/stdc++.h>
#define int long long
using namespace std;

unordered_map<string, vector<string>> graph;
unordered_map<string, unordered_map<string, int>> memo;

int dfs(const string &node, const string &to) {
    if (node == to) return 1;
    if (memo[node].count(to)) return memo[node][to];

    int res = 0;
    for (auto &n : graph[node])
        res += dfs(n, to);

    return memo[node][to] = res;
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

    int p1 = dfs("svr", "dac") * dfs("dac", "fft") * dfs("fft", "out");
    int p2 = dfs("svr", "fft") * dfs("fft", "dac") * dfs("dac", "out");

    cout << (p1 + p2);
}
