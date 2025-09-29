#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e9 + 9;
int n, M;
ll qmi(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
ll inv(ll x) {
    return qmi(x, M - 2);
}
ll f(ll p, ll q) {
    return p % M * inv(q % M) % M;
}
void solve() {
    cin >> n >> M;
    for (int i = 1; i <= n; i++) cout << inv(i) << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}