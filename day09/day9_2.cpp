#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    ifstream fin("in_day9.txt");

    vector<pair<int, int>> coords;
    int x, maxi = 0;
    char _;
    while (fin >> x) {
        int y;
        fin >> _ >> y;
        coords.emplace_back(x, y);
    }
    for (int i = 0; i < coords.size()-1; i++) {
        for (int j = i+1; j < coords.size(); j++) {
            if ((abs(coords[i].first-coords[j].first)+1)*(abs(coords[i].second-coords[j].second)+1) > maxi) {
                bool can = true;
                int xB = min(coords[i].first, coords[j].first);
                int xE = max(coords[i].first, coords[j].first);
                int yB = min(coords[i].second, coords[j].second);
                int yE = max(coords[i].second, coords[j].second);

                for (int k = 0; k < coords.size() - 1 && can; k++) {
                    int x1 = coords[k].first, y1 = coords[k].second;
                    int x2 = coords[k+1].first, y2 = coords[k+1].second;

                    if (x1 == x2) {
                        int x = x1;
                        if (xB < x && x < xE) {
                            int lo = min(y1, y2);
                            int hi = max(y1, y2);
                            if (hi > yB && lo < yE) {
                                can = false;
                                break;
                            }
                        }
                    }
                    else if (y1 == y2) {
                        int y = y1;
                        if (yB < y && y < yE) {
                            int lo = min(x1, x2);
                            int hi = max(x1, x2);
                            if (hi > xB && lo < xE) {
                                can = false;
                                break;
                            }
                        }
                    }
                }
                if (can) maxi = (abs(coords[i].first-coords[j].first)+1)*(abs(coords[i].second-coords[j].second)+1);
            }
        }
    }
    cout << maxi;
}