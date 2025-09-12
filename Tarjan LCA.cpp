#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int fa[N], dep[N], pre[N], ans[N];
bitset<N> vis;
vector<int> g[N];
vector<pair<int, int>> Q[N];
int find(int x) {
    return pre[x] = (x == pre[x] ? x : find(pre[x]));
}
void merge(int x, int y) {
    //将深度大的指向深度小的
    int fx = find(x), fy = find(y);
    if (dep[fx] < dep[fy]) swap(fx, fy);
    pre[fx] = fy;
}
void dfs(int x) {
    dep[x] = dep[fa[x]] + 1;
    vis[x] = true;
    //处理儿子所在子树
    for (auto &y : g[x]) dfs(y);
    //处理自己的询问
    for (auto &[y, id] : Q[x]) {
        if (!vis[y]) continue;
        ans[id] = find(y);
    }
    //合并
    merge(x, fa[x]);
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) pre[i] = i;
    for (int i = 2; i <= n; i++) {
        cin >> fa[i];
        g[fa[i]].push_back(i);
    }
    int q; cin >> q;
    for (int i = 1; i <= q; i++) {
        int x, y;
        cin >> x >> y;
        Q[x].push_back({y, i});
        Q[y].push_back({x, i});
    }
    dfs(1);
    for (int i = 1; i <= q; i++) cout << ans[i] << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    /*int t; cin >> t;
    while(t--)*/
        solve();
    return 0;
}