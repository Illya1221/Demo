#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 1e5 + 9;
const int inf = 2e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int p = 1e9 + 7;
ll phi[N];
void euler_sieve(ll n) {
    bitset<N> vis;
    vis[0] = vis[1] = true;
    vector<int> prime;
    phi[1] = 1;
    for (ll i = 2; i <= n; i++) {
        if (!vis[i]) {
            prime.push_back(i);
           phi[i] = i - 1;
        }
        for (auto j : prime) {
            if (i * j > n) break;
            vis[i * j] = true;
            if (!(i % j)) {
                phi[i * j] = phi[i] * j;
                break;
            }
            phi[i * j] = phi[i] * phi[j];
        }
    }
    for (int i = 1; i <= n; i++) phi[i] += phi[i - 1];
}
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
void solve() {
    ll n; cin >> n;
    ll ans = 0;
    for (ll l = 1, r = 1; l <= n; l = r + 1) {
        r = min(n, n / (n / l));
        ans = mo(ans + (n / l) * (n / l) % p * mo(phi[r] - phi[l - 1]) % p);
    }
    ans = mo(ans - mo(n * (n + 1) % p * inv2 % p)) * inv2 % p;
    cout << ans << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    euler_sieve(1e5);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}