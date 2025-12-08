#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Coords {
    int x, y, z;

    Coords(int a, int b, int c) {
        x = a, y = b, z = c;
    }
};

vector<Coords> pos;

struct Dist {
    int d, a, b;

    Dist(int pa, int pb) {
        a = pa, b = pb;
        Coords pA = pos[pa], pB = pos[pb];
        int dx = pA.x - pB.x;
        int dy = pA.y - pB.y;
        int dz = pA.z - pB.z;
        d = dx*dx + dy*dy + dz*dz;
    }
    bool operator<(const Dist& o) const {
        return d < o.d;
    }
};

class UnionFind {
public:
    vector<int> parents;
    int n;
    UnionFind(int N) {
        n = N;
        parents.resize(n);
        for (int i = 0; i < n; i++) parents[i] = -1;
    }

    int ancestor(int u) {
        if (parents[u] == -1) return u;
        parents[u] = ancestor(parents[u]);
        return parents[u];
    }

    void merge(int a, int b) {
        int pA = ancestor(a), pB = ancestor(b);
        if (pA != pB) parents[pA] = pB;
    }

    vector<int> biggest() {
        unordered_map<int, int> um;

        for (int i = 0; i < n; i++) {
            int p = ancestor(i);
            um[p]++;
        }
        vector<int> v;
        for (auto &kv : um) v.push_back(kv.second);
        sort(v.rbegin(), v.rend());

        return v;
    }
};

signed main() {
    ifstream fin("in_day8.txt");
    
    int n = 1000;
    int a;
    while (fin >> a) {
        int b, c;
        char _;
        fin >> _ >> b >> _ >> c;
        pos.push_back(Coords(a, b, c));
    }
    vector<Dist> v;

    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            v.emplace_back(i, j);

    sort(v.begin(), v.end());

    UnionFind DSU(n);

    for (int i = 0; i < 1000; i++) {
        Dist cur = v[i];
        DSU.merge(cur.a, cur.b);
    }
    vector<int> b = DSU.biggest();
    cout << b[0]*b[1]*b[2];
}