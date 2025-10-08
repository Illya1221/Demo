#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 5e3 + 9;
const int INF = 2e9;
const int mod = 1e9 + 7;
struct Node {
    ll x, w;
    bool operator < (const Node &u) const {
        return w == u.w ? x > u.x : w > u.w;
    }
};
ll n, m, d[N];
bitset<N> vis;
vector<Node> g[N];
priority_queue<Node> pq;
void Prim() {
    memset(d, 0x3f, sizeof(d));
    pq.push({1, 0});
    ll ans = 0;
    d[1] = 0;
    while (!pq.empty()) {
        int x = pq.top().x; pq.pop();
        if (vis[x]) continue;
        vis[x] = true;
        ans += d[x];
        d[x] = 0;
        for (auto [y, w] : g[x]) {
            if (!vis[y] && w < d[y]) {
                d[y] = w;
                pq.push({y, w});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cout << "orz";
            return;
        }
    }
    cout << ans;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    Prim();
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}