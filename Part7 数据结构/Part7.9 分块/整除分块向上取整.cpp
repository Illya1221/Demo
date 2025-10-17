#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 9;
const int inf = 2e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int p = 1e9 + 7;
ll qmi(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
ll inv(ll x) {
    return qmi(x, p - 2);
}
ll inv2 = inv(2);
ll mo(ll x) {
    return (x % p + p) % p;
}
ll findr(ll n, ll l) {
    ll k = (n + l - 1) / l;
    if (k == 1) return n;
    return (n - 1) / (k - 1);
}
void solve() {
    ll n; cin >> n;
    ll ans = 0;
    for (ll l = 1, r = 1; l <= n; l = r + 1) {
        r = min(n, findr(n, l));
        ans = mo(ans + mo((n + l - 1) / l) * mo(l + r) % p * mo(r - l + 1) % p * inv2 % p);
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