#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 1e5 + 9;
const int inf = 2e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
ll mu[N];
void euler_sieve(int n) {
    bitset<N> vis;
    vis[0] = vis[1] = true;
    vector<int> prime;
    mu[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            prime.push_back(i);
            mu[i] = -1;
        }
        for (auto j : prime) {
            if (i * j > n) break;
            vis[i * j] = true;
            if (!(i % j)) {
                mu[i * j] = 0;
                break;
            }
            mu[i * j] = -mu[i];
        }
    }
}
void solve() {
    int x; cin >> x;
    cout << mu[x] << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    euler_sieve(1e5);
    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}