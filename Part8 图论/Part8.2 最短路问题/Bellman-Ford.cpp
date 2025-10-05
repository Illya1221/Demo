#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e3;
int n, m, cnt[N], d[N];
struct Node {
    int x, w;
};
vector<Node> g[N];
bool BellmanFord(int st) {
    memset(cnt, 0, sizeof cnt);
    memset(d, 0x3f, sizeof d);
    queue<int> q;
    bitset<N> vis;
    d[st] = 0;
    q.push(st);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        vis[x] = false;
        for (auto &[y, w] : g[x]) {
            if (d[y] > d[x] + w) {
                d[y] = d[x] + w;
                cnt[y] = cnt[x] + 1;
                if (cnt[y] >= n) return true;
                if (!vis[y]) {
                    q.push(y);
                    vis[y] = true;
                }
            }
        }
    }
    return false;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        if (w >= 0)
            g[v].push_back({u, w});
    }
    if (BellmanFord(1)) cout << "YES\n";
    else cout << "NO\n";
    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}