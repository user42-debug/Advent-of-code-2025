#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("in_day5.txt");

    vector<pair<long long,long long>> ingredients;
    string line;

    while (getline(fin, line)) {
        if (line.empty()) break;
        if (line.find('-') == string::npos) {
            fin.clear();
            fin.seekg(-(long long)line.size() - 1, ios::cur);
            break;
        }

        stringstream ss(line);
        long long a, b;
        char dash;
        ss >> a >> dash >> b;
        ingredients.emplace_back(a, b);
    }
    sort(ingredients.begin(), ingredients.end());
    long long maxi = 0, res = 0;
    for (auto p : ingredients) {
        if (p.second > maxi) {
            res += p.second - max(maxi, p.first-1);
            maxi = p.second;
        }
    }
    cout << res;
}
