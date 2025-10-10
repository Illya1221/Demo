#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 9;
const int INF = 2e9;
const int mod = 1e9 + 7;
const int MOD = 998244353;

ll n = 2e5, t[N << 2];

void pushup(int o) {
    t[o] = t[o << 1] + t[o << 1 | 1];
}
void insert(int val, int s = 1, int e = n, int o = 1) {
    if (s == e) {
        t[o]++;
        return;
    }
    int mid = (s + e) >> 1;
    if (val <= mid) insert(val, s, mid, o << 1);
    else insert(val, mid + 1, e, o << 1 | 1);
    pushup(o);
}
int queryCnt(int l, int r, int s = 1, int e = n, int o = 1) {
    if (l <= s && e <= r) return t[o];
    int mid = (s + e) >> 1;
    int res = 0;
    if (mid >= l) res += queryCnt(l, r, s, mid, o << 1);
    if (mid + 1 <= r) res += queryCnt(l, r, mid + 1, e, o << 1 | 1);
    return res;
}
int queryVal(int k, int s = 1, int e = n, int o = 1) {
    if (s == e) return s;
    int left_sum = t[o << 1];
    int mid = (s + e) >> 1;
    if (k <= left_sum) return queryVal(k, s, mid, o << 1);
    else return queryVal(k - left_sum, mid + 1, e, o << 1 | 1);
}
void solve() {
    int q; cin >> q;
    while (q--) {
        int opt; cin >> opt;
        if (opt == 1) {
            int x; cin >> x;
            insert(x);
        }
        if (opt == 2) {
            int l, r; cin >> l >> r;
            cout << queryCnt(l, r) << '\n';
        }
        if (opt == 3) {
            int k; cin >> k;
            cout << queryVal(k) << '\n';
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