#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e9 + 9;
void solve() {
    int n, m; cin >> n >> m;
    if (n > m) swap(n, m);
    long double gold = (1.0 + sqrt(5.0)) / 2.0;
    long double k = (long double)(m - n);
    int test = (int)(k * gold);
    if (test == n) cout << 0;
    else cout << 1;
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}