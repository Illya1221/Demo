#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 9;
int pre[N], d[N];
int find(int k) {
    if (pre[k] == k) return k;
    int fa = pre[k];
    pre[k] = find(pre[k]);
    d[k] += d[fa];
    return pre[k];
}
int mo(int x) {
    return (x + 2) % 2;
}
int getd(int x) {
    int res = 0;
    while (pre[x] != x) {
        res += d[x];
        x = pre[x];
    }
    return res;
}
void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    pre[fx] = fy;
    d[fx] = mo(d[y] - d[x] + 1);
}
void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) pre[i] = i;
    while (q--) {
        int opt, x, y;
        cin >> opt >> x >> y;
        if (opt == 1) merge(x, y);
        if (opt == 2) {
            int rx = find(x), ry = find(y);
            if (rx != ry) cout << "Unknown\n";
            else if (mo(d[x] - d[y]) == 1) cout << "NO\n";
            else cout << "YES\n";
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