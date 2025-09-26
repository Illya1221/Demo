#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e9 + 5;
ll p;
ll qmi(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
void solve() {
    ll a, b;
    cin >> a >> b >> p;
    cout << a << '^' << b << " mod " << p << '=' << qmi(a, b);
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}