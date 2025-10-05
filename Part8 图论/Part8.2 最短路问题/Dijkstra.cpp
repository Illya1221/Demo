#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int n, m, s;
ll d[N];
struct Node {
    ll x, w;
    bool operator < (const Node &u) const {
        return w == u.w ? (x > u.x) : (w > u.w);
    }
};
vector<Node> g[N];
priority_queue<Node> pq;
void dijkstra(int st) {
    memset(d, 0x3f, sizeof(d));
    d[st] = 0;
    bitset<N> vis;
    pq.push({st, d[st]});
    while(!pq.empty()) {
        int x = pq.top().x; pq.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (auto &[y, w] : g[x]) {
            if (!vis[y] && d[y] > d[x] + w) {
                d[y] = d[x] + w;
                pq.push({y, d[y]});
            }
        }
    }
}
void solve() {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        if (u != v) g[u].push_back({v, w});
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) {
        cout << d[i] << ' ';
    }
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //int t; cin >> t;
    //while(t--)
        solve();
    return 0;
}