#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 5;
int n, m, pre[N];
struct Edge {
    int u, v, w;
    bool operator < (const Edge &m) const {
        return w == m.w ? (u == m.u ? (v < m.v) : (u < m.u)) : (w < m.w);
    }
};
vector<Edge> eg;
int root(int k) {
    return pre[k] = (k == pre[k] ? k : root(pre[k]));
}
void kruskal() {
    for (int i = 1; i <= n; i++) {
        pre[i] = i;
    }
    ll ans = 0;
    for (auto &[x, y, z] : eg) {
        if (root(x) != root(y)) {
            ans += z;
            pre[root(x)] = root(y);
        }
    }
    for (int i = 2; i <= n; i++) {
        if (root(i) != root(i - 1)) {
            cout << "orz";
            return;
        }
    }
    cout << ans;
    return;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, z; cin >> x >> y >> z;
        eg.push_back({x, y, z});
    }
    sort(eg.begin(), eg.end());
    kruskal();
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    /*int t; cin >> t;
    while(t--)*/
        solve();
    return 0;
}