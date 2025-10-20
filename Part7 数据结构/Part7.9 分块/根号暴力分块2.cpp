#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 9;
const int inf = 2e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
ll sz, a[N], add[N], L[N], R[N], bel[N];
vector<ll> v[N];
void resort(int blo) {
    v[blo].clear();
    for (int i= L[blo]; i <= R[blo]; i++) {
        v[blo].push_back(a[i]);
    }
    stable_sort(v[blo].begin(), v[blo].end());
}
void Add(int l, int r, ll x) {
    if (bel[l] == bel[r]) {
        for (int i = l; i <= r; i++) {
            a[i] += x;
        }
        resort(bel[l]);
        return;
    }
    for (int i = l; i <= R[bel[l]]; i++) {
        a[i] += x;
    }
    resort(bel[l]);
    for (int blo = bel[l] + 1; blo < bel[r]; blo++) {
        add[blo] += x;
    }
    for (int i = L[bel[r]]; i <= r; i++) {
        a[i] += x;
    }
    resort(bel[r]);
}
int f(int l, int r, ll x) {
    int res = 0;
    if (bel[l] == bel[r]) {
        for (int i = l; i <= r; i++) {
            res += (int) (a[i] + add[bel[i]] < x);
        }
        return res;
    }
    for (int i = l; i <= R[bel[l]]; i++) {
        res += (int) (a[i] + add[bel[i]] < x);
    }
    for (int blo = bel[l] + 1; blo < bel[r]; blo++) {
        res += lower_bound(v[blo].begin(), v[blo].end(), x) - v[blo].begin();
    }
    for (int i = L[bel[r]]; i <= r; i++) {
        res += (int) (a[i] + add[bel[i]] < x);
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
        if (i > 1 && bel[i] != bel[i - 1]) {
            L[bel[i]] = i;
            R[bel[i - 1]] = i - 1;
        }
    }
    L[bel[1]] = 1, R[bel[n]] = n;
    for (int blo = bel[1]; blo <= bel[n]; blo++) {
        resort(blo);
    }
    int m; cin >> m;
    while (m--) {
        ll opt, l, r, x;
        cin >> opt >> l >> r >> x;
        if (opt == 1) {
            Add(l, r, x);
        }
        if (opt == 2) {
            cout << f(l, r, x) << '\n';
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