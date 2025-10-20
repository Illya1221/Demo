#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 9;
const int inf = 2e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
ll sz, a[N], sum[N], add[N], L[N], R[N], bel[N];
void Add(int l, int r, ll x) {
    if (bel[l] == bel[r]) {
        for (int i = l; i <= r; i++) {
            a[i] += x;
            sum[bel[i]] += x;
        }
        return;
    }
    for (int i = l; i <= R[bel[l]]; i++) {
        a[i] += x;
        sum[bel[i]] += x;
    }
    for (int blo = bel[l] + 1; blo < bel[r]; blo++) {
        add[blo] += x;
    }
    for (int i = L[bel[r]]; i <= r; i++) {
        a[i] += x;
        sum[bel[i]] += x;
    }
}
ll getsum(int l, int r) {
    ll res = 0;
    if (bel[l] == bel[r]) {
        for (int i = l; i <= r; i++) {
            res += a[i] + add[bel[i]];
        }
        return res;
    }
    for (int i = l; i <= R[bel[l]]; i++) {
        res += a[i] + add[bel[i]];
    }
    for (int blo = bel[l] + 1; blo < bel[r]; blo++) {
        res += sum[blo] + add[blo] * (R[blo] - L[blo] + 1);
    }
    for (int i = L[bel[r]]; i <= r; i++) {
        res += a[i] + add[bel[i]];
    }
    return res;
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sz = sqrt(n) + 1;
    for (int i = 1; i <= n; i++) {
        bel[i] = i / sz + 1;
        sum[bel[i]] += a[i];
        if (i > 1 && bel[i] != bel[i - 1]) {
            L[bel[i]] = i;
            R[bel[i - 1]] = i - 1;
        }
    }
    L[bel[1]] = 1, R[bel[n]] = n;
    int m; cin >> m;
    while (m--) {
        int opt, l, r;
        cin >> opt >> l >> r;
        if (opt == 1) {
            ll x; cin >> x;
            Add(l, r, x);
        }
        if (opt == 2) {
            cout << getsum(l, r) << '\n';
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