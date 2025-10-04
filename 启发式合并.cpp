#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 9;
int pre[N], sz[N], a[N];
int find(int k) {
    return k == pre[k] ? k : find(pre[k]);
}
void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    if (sz[fx] > sz[fy]) swap(fx, fy);
    pre[fx] = fy;
    sz[fy] += sz[fx];
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pre[i] = i, sz[i] = 1;
    int m; cin >> m;
    while (m--) {
        int x, y; cin >> x >> y;
        merge(x, y);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) if (pre[i] != i) a[find(i)] ^= a[i];
    for (int i = 1; i <= n; i++) if (pre[i] == i) ans = max(ans, a[i]);
    cout << ans;
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}