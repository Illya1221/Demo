#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 9;
int pre[N], sz[N], top;
pair<int, int> stk[N];
int find(int k) {
    return k == pre[k] ? k : find(pre[k]);
}
void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if (fx == fy) return;
    if (sz[fx] > sz[fy]) swap(fx, fy);
    stk[++top] = {fx, fy};
    pre[fx] = fy;
    sz[fy] += sz[fx];
}
void undo() {
    if (!top) return;
    auto [x, y] = stk[top--];
    pre[x] = x;
    sz[y] -= sz[x];
}
void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) pre[i] = i, sz[i] = 1;
    while (q--) {
        int opt, x, y;
        cin >> opt;
        if (opt == 1) {
            cin >> x >> y;
            merge(x, y);
        }
        if (opt == 2) undo();
        if (opt == 3) {
            cin >> x >> y;
            if (find(x) == find(y)) cout << "YES\n";
            else cout << "NO\n";
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