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
    int n, groups;
    UnionFind(int N) {
        n = N;
        groups = n;
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
        if (pA != pB) {
            parents[pA] = pB;
            groups--;
        }
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
    int res;

    for (int i = 0; DSU.groups > 1; i++) {
        Dist cur = v[i];
        if (DSU.ancestor(cur.a) != DSU.ancestor(cur.b)) {
            DSU.merge(cur.a, cur.b);
            res = pos[cur.a].x * pos[cur.b].x;
        }
    }
    cout << res;
}