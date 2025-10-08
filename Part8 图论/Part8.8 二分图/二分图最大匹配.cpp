#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 5e2 + 9;
const int INF = 2e9;
const int mod = 1e9 + 7;
vector<int> g[N];
int p[N], vis[N], dfn;
bool dfs(int x) {
    for (auto y : g[x]) {
        if (vis[y] == dfn) continue;
        vis[y] = dfn;
        if (!p[y] || dfs(p[y])) {
            p[y] = x;
            return true;
        }
    }
    return false;
}
void solve() {
    int n, m, e; cin >> n >> m >> e;
    for (int i = 1; i <= e; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dfn++;
        if (dfs(i)) ans++;
    }
    cout << ans;
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}