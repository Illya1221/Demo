#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 9;
const int INF = 2e9;
const int mod = 1e9 + 7;
ll n, m, r, p;
ll a[N], t[N << 2], lz[N << 2];
ll sz[N], fa[N], dep[N], son[N], top[N], dfn[N];
vector<int> g[N];
void dfs1(int x, int f) {
    dep[x] = dep[f] + 1;
    sz[x] = 1;
    fa[x] = f;
    for (auto y : g[x]) {
        if (y == f) continue;
        dfs1(y, x);
        sz[x] += sz[y];
        if (sz[y] > sz[son[x]]) son[x] = y;
    }
}
int idx = 0;
void dfs2(int x, int t) {
    dfn[x] = ++idx;
    top[x] = t;
    if (son[x]) dfs2(son[x], t);
    for (auto y : g[x]) {
        if (y == fa[x] || y == son[x]) continue;
        dfs2(y, y);
    }
}
void update(int s, int e, int o, ll x) {
    t[o] = (t[o] + (e - s + 1) * x) % p;
    lz[o] = (lz[o] + x) % p;
}
void pushup(int o) {
    t[o] = (t[o << 1] + t[o << 1 | 1]) % p;
}
void pushdown(int s, int e, int o) {
    if (!lz[o]) return;
    int mid = (s + e) >> 1, ls = o << 1, rs = o << 1 | 1;
    update(s, mid, o << 1, lz[o]);
    update(mid + 1, e, o << 1 | 1, lz[o]);
    lz[o] = 0;
}
void buildTree(int s = 1, int e = n, int o = 1) {
    if (s == e) {
        t[o] = a[s];
        return;
    }
    int mid = (s + e) >> 1;
    buildTree(s, mid, o << 1), buildTree(mid + 1, e, o << 1 | 1);
    pushup(o);
}
void add(int l, int r, ll x, int s = 1, int e = n, int o = 1) {
    if (l <= s && e <= r) {
        update(s, e, o, x);
        return;
    }
    pushdown(s, e, o);
    int mid = (s + e) >> 1;
    if (mid >= l) add(l, r, x, s, mid, o << 1);
    if (mid + 1 <= r) add(l, r, x, mid + 1, e, o << 1 | 1);
    pushup(o);
}
ll query(int l, int r, int s = 1, int e = n, int o = 1) {
    if (l <= s && e <= r) return t[o];
    pushdown(s, e, o);
    int mid = (s + e) >> 1;
    ll res = 0;
    if (mid >= l) res = (res + query(l, r, s, mid, o << 1)) % p;
    if (mid + 1 <= r) res = (res + query(l, r, mid + 1, e, o << 1 | 1)) % p;
    return res;
}
void solve() {
    cin >> n >> m >> r >> p;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs1(r, 0);
    dfs2(r, r);
    for (int i = 1; i <= n; i++) add(dfn[i], dfn[i], a[i]);
    while (m--) {
        int opt, x, y, z;
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y >> z;
            while (top[x] != top[y]) {
                if (dep[top[x]] < dep[top[y]]) swap(x, y);
                //将这一条链[top[x], x]上的点都增加z
                add(dfn[top[x]], dfn[x], z);
                x = fa[top[x]];
            }
            if (dep[x] < dep[y]) swap(x, y);
            add(dfn[y], dfn[x], z);
        }
        if (opt == 2) {
            cin >> x >> y;
            ll ans = 0;
            while (top[x] != top[y]) {
                if (dep[top[x]] < dep[top[y]]) swap(x, y);
                //将这一条链[top[x], x]上的点都加上
                ans = (ans + query(dfn[top[x]], dfn[x])) % p;
                x = fa[top[x]];
            }
            if (dep[x] < dep[y]) swap(x, y);
            ans = (ans + query(dfn[y], dfn[x])) % p;
            cout << ans << '\n';
        }
        if (opt == 3) {
            cin >> x >> z;
            add(dfn[x], dfn[x] + sz[x] - 1, z);
        }
        if (opt == 4) {
            cin >> x;
            cout << query(dfn[x], dfn[x] + sz[x] - 1) << '\n';
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}