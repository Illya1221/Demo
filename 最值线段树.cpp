#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
const ll INF = 2e18;
int n, m;
ll a[N], tMax[N << 2], tMin[N << 2], lz[N << 2];
void update(int s, int e, int o, ll x) {
    tMax[o] += x; tMin[o] += x;
    lz[o] += x;
}
void pushup(int o) {
    tMax[o] = max(tMax[o << 1], tMax[o << 1 | 1]);
    tMin[o] = min(tMin[o << 1], tMin[o << 1 | 1]);
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
        tMax[o] = tMin[o] = a[s];
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
ll queryMax(int l, int r, int s = 1, int e = n, int o = 1) {
    if (l <= s && e <= r) return tMax[o];
    pushdown(s, e, o);
    int mid = (s + e) >> 1;
    ll res = -INF;
    if (mid >= l) res = max(res, queryMax(l, r, s, mid, o << 1));
    if (mid + 1 <= r) res = max(res, queryMax(l, r, mid + 1, e, o << 1 | 1));
    return res;
}
ll queryMin(int l, int r, int s = 1, int e = n, int o = 1) {
    if (l <= s && e <= r) return tMin[o];
    pushdown(s, e, o);
    int mid = (s + e) >> 1;
    ll res = INF;
    if (mid >= l) res = min(res, queryMin(l, r, s, mid, o << 1));
    if (mid + 1 <= r) res = min(res, queryMin(l, r, mid + 1, e, o << 1 | 1));
    return res;
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    buildTree();
    while (m--) {
        int opt, x, y; ll k;
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y >> k;
            add(x, y, k);
        }
        if (opt == 2) {
            cin >> x >> y;
            cout << queryMax(x, y) << '\n';
        }
        if (opt == 3) {
            cin >> x >> y;
            cout << queryMin(x, y) << '\n';
        }
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