#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e3 + 9;
const int INF = 1e9;
struct Node {
    ll x, w;
    bool operator < (const Node &u) const {
        return w == u.w ? x > u.x : w > u.w;
    }
};
vector<Node> g[N];
ll n, m, h[N], d[N][N];
bool spfa(int st) {
    for (int i = 1; i <= n; i++) h[i] = INF;
    bitset<N> vis;
    queue<int> q;
    vector<int> cnt(n + 1);
    q.push(st);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        vis[x] = false;
        for (auto [y, w] : g[x]) {
            if (h[y] > h[x] + w) {
                h[y] = h[x] + w;
                if (++cnt[y] > n) return true;
                if (!vis[y]) {
                    q.push(y);
                    vis[y] = true;
                }
            }
        }
    }
    return false;
}
void dijkstra(int st, ll d[]) {
    for (int i = 1; i <= n; i++) d[i] = INF;
    d[st] = 0;
    priority_queue<Node> pq;
    bitset<N> vis;
    pq.push({st, d[st]});
    while (!pq.empty()) {
        int x = pq.top().x; pq.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (auto [y, w] : g[x]) {
            if (!vis[y] && d[y] > d[x] + w) {
                d[y] = d[x] + w;
                pq.push({y, d[y]});
            }
        }
    }
    for (int i = 1; i <= n; i++) if (d[i] != INF) d[i] += h[i] - h[st];
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        ll u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    for (int i = 1; i <= n; i++) g[0].push_back({i, 0});
    if (spfa(0)) {
        cout << -1 << '\n';
        return;
    }
    for (int x = 1; x <= n; x++)
        for (auto &[y, w] : g[x]) w += h[x] - h[y];
    for (int i = 1; i <= n; i++) dijkstra(i, d[i]);
    for (int i = 1; i <= n; i++) {
        ll res = 0;
        for (int j = 1; j <= n; j++) {
            res += j * d[i][j];
        }
        cout << res << '\n';
    }
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}