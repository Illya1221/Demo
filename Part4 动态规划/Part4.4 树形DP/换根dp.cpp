#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 9;
const int INF = 2e9;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const int MOD = 998244353;
ll sz[N], dp[N], ans = inf, cnt;
vector<int> g[N];
bitset<N> p;
void dfs1(int x, int fa) {
    sz[x] = p[x];
    for (auto y : g[x]) {
        if (y == fa) continue;
        dfs1(y, x);
        sz[x] += sz[y];
        dp[x] += dp[y] + sz[y];
    }
}
void dfs2(int x, int fa) {
    if (dp[x] == ans) cnt++;
    else if (dp[x] < ans) {
        ans = dp[x];
        cnt = 1;
    }
    for (auto y : g[x]) {
        if (y == fa) continue;
        int dpx = dp[x], dpy = dp[y];
        int szx = sz[x], szy = sz[y];
        dp[x] -= dp[y] + sz[y];
        sz[x] -= sz[y];
        dp[y] += dp[x] + sz[x];
        sz[y] += sz[x];
        dfs2(y, x);
        dp[x] = dpx, dp[y] = dpy;
        sz[x] = szx, sz[y] = szy;
    }
}
void solve() {
    int n, k; cin >> n >> k;
    for (int i = 1; i <= k; i++) {
        int x; cin >> x;
        p[x] = true;
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    cout << ans << ' ' << cnt;
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}