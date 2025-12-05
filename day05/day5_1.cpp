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
    long long cur;
    int res = 0;
    while (fin >> cur) {
        for (auto p : ingredients) {
            if (p.first > cur) break;
            if (p.second >= cur) {
                res++;
                break;
            }
        }
    }
    cout << res;
}
