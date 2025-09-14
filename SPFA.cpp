#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int n, m, s;
ll d[N];
struct Node {
    ll x, w;
};
vector<Node> g[N];
queue<int> q;
void spfa(int st) {
    memset(d, 0x3f, sizeof(d));
    d[st] = 0;
    bitset<N> vis;
    q.push(st);
    vis[st] = true;
    while(!q.empty()) {
        int x = q.front(); q.pop();
        vis[x] = false;
        for (auto &[y, w] : g[x]) {
            if (d[y] > d[x] + w) {
                d[y] = d[x] + w;
                if (!vis[y]) {
                    q.push(y);
                    vis[y] = true;
                }
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
    spfa(s);
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