#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 9;
const int INF = 2e9;
struct Node {
    int x, w;
};
vector<Node> g[N];
ll d[N];
void solve() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    for (int i = 2; i <= n; i++) d[i] = INF;
    bool circle = false;
    for (int i = 1; i <= n; i++) {
        circle = false;
        for (int x = 1; x <= n; x++) {
            for (auto [y, w] : g[x]) {
                if (d[x] + w < d[y]) {
                    d[y] = d[x] + w;
                    circle = true;
                }
            }
        }
    }
    if (circle) cout << -1 << '\n';
    else for (int i = 1; i <= n; i++) cout << d[i] << ' ';
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}