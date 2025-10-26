#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 9;
const int M = 4e5 + 9;
const int inf = 2e9;
// const int INF = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
int dfn[N], low[N], compId[N], col[N], idx, compCnt;
bitset<M> isBright;
vector<int> comps[N];
vector<pair<int, int>> g[N];
void tarjan(int x, int f) {
    dfn[x] = low[x] = ++idx;
    for (auto [y, i] : g[x]) {
        if (i == f) continue;
        if (!dfn[y]) {
            tarjan(y, i);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x]) {
                isBright[i] = true;
            }
        } else {
            low[x] = min(low[x], dfn[y]);
        }
    }
}
void dfs(int x) {
    compId[x] = compCnt;
    comps[compCnt].push_back(x);
    for (auto [y, i] : g[x]) {
        if (isBright[i]) {
            continue;
        }
        if (compId[y] == -1) {
            dfs(y);
        }
    }
}
bool is_bipartite(int st) {
    col[st] = 0;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (auto [y, i] : g[x]) {
            if (isBright[i]) {
                continue;
            }
            if (compId[x] != compId[y]) {
                continue;
            }
            if (col[y] == -1) {
                col[y] = col[x] ^ 1;
                q.push(y);
            } else if (col[x] == col[y]) {
                return false;
            }
        }
    }
    return true;
}
void solve() {
    int n, m, V; cin >> n >> m >> V;
    idx = compCnt = 0;
    for (int i = 1; i <= n; i++) {
        dfn[i] = low[i] = 0;
        compId[i] = col[i] = -1;
        g[i].clear(); comps[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        isBright[i] = false;
    }
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i, -1);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (compId[i] == -1) {
            compCnt++;
            dfs(i);
        }
    }
    ll ans = 1;
    for (int i = 1; i <= compCnt; i++) {
        for (auto j : comps[i]) {
            col[j] = -1;
        }
        bool bipartite = is_bipartite(comps[i][0]);
        if (bipartite) {
            int x = -1;
            for (auto j : comps[i]) {
                if (a[j] != -1) {
                    if (x == -1) x = a[j];
                    else if (x != a[j]) {
                        cout << 0 << '\n';
                        return;
                    }
                }
            }
            if (x == -1) ans = 1ll * ans * V % mod;
        } else {
            for (auto j : comps[i]) {
                if (a[j] > 0) {
                    cout << 0 << '\n';
                    return;
                }
            }
        }
    }
    cout << ans << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}