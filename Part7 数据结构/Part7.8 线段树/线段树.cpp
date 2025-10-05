#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
int n, m;
ll a[N], t[N << 2], lz[N << 2];
void update(int s, int e, int o, ll x) {
    t[o] += (e - s + 1) * x;
    lz[o] += x;
}
void pushup(int o) {
    t[o] = t[o << 1] + t[o << 1 | 1];
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
    if (mid >= l) res += query(l, r, s, mid, o << 1);
    if (mid + 1 <= r) res += query(l, r, mid + 1, e, o << 1 | 1);
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
            cout << query(x, y) << '\n';
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