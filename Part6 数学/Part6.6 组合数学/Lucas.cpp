#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 9;
const int inf = 2e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
ll qmi(ll a, ll b, ll p) {
    ll res = 1;
    while (b) {
        if (b & 1) b = b * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
ll inv(ll a, ll p) {
    return qmi(a, p - 2, p);
}
ll fac[N], invfac[N];
ll C(ll n, ll m, ll p) {
    if (n < m) return 0;
    if (n < p && m < p) return fac[n] * invfac[m] % p * invfac[n - m] % p;
    return C(n / p, m / p, p) * C(n % p, m % p, p) % p;
}
void solve() {
    ll n, m, p; cin >> n >> m >> p;
    fac[0] = 1;
    for (int i = 1; i < p; i++) fac[i] = fac[i - 1] * i % p;
    invfac[p - 1] = inv(fac[p - 1], p);
    for (int i = p - 1; i > 0; i--) invfac[i - 1] = invfac[i] * i % p;
    cout << C(n + m, m, p) << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}