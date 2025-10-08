#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 9;
const int INF = 2e9;
const int mod = 1e9 + 7;
vector<int> g[N];
int fa[N], dep[N], son[N], top[N], sz[N];
void dfs1(int x, int f) {
    dep[x] = dep[f] + 1;
    sz[x] = 1;
    for (auto y : g[x]) {
        if (y == f) continue;
        dfs1(y, x);
        sz[x] += sz[y];
        if (sz[y] > sz[son[x]]) son[x] = y;
    }
}
void dfs2(int x, int t) {
    top[x] = t;
    //先走重儿子
    if (son[x]) dfs2(son[x], t);
    //走轻儿子
    for (auto y : g[x]) {
        if (y == son[x]) continue;
        dfs2(y, y);
    }
}
int lca(int x, int y) {
    //不在同一条重链上
    while (top[x] != top[y]) {
        //将top偏下的往上跳
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        //保证x所在的链是深度较大的
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    return y;
}
void solve() {
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> fa[i];
        g[fa[i]].push_back(i);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    int m; cin >> m;
    while (m--) {
        int x, y; cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}