#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 4e4 + 9;
vector<int> prime;
bitset<N> vis;
int phi[N];
void get_phi() {
    vis[0] = vis[1] = true;
    for (int i = 2; i <= N; i++) {
        if (!vis[i]) {
            prime.push_back(i);
            phi[i] = i - 1;
        }
        for (const auto &j : prime) {
            if (i * j > N) break;
            vis[i * j] = true;
            if (!(i % j)) {
                phi[i * j] = phi[i] * j;
                break;
            }
            phi[i * j] = phi[i] * phi[j];
        }
    }
}
int pre[N];
void solve() {
    int n; cin >> n;
    get_phi(); pre[1] = 1;
    for (int i = 2; i <= n; i++) pre[i] += pre[i - 1] + phi[i];
    if (n == 1) cout << 0;
    else cout << 2 * pre[n - 1] + 1;
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}