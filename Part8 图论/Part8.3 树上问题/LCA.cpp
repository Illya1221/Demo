#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9, T = 20;
int fa[N][30], dep[N];
vector<int> g[N];
void dfs(int x) {
    dep[x] = dep[fa[x][0]] + 1; //更新深度
    for (int i = 1; i <= T; i++) //倍增求父节点
        fa[x][i] = fa[fa[x][i - 1]][i - 1];
    for (auto &y : g[x]) dfs(y); //遍历每一个子节点
}
int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y); //使dep[x] >= dep[y]
    for (int i = T; i >= 0; i--) //先跳到深度相同的点
        if (dep[fa[x][i]] >= dep[y]) x = fa[x][i];
    if (x == y) return x; //如果两点在该深度重合则lca就是该点
    for (int i = T; i >= 0; i--) //往上一起跳
        if (fa[x][i] != fa[y][i]) //保证不要超出lca的深度
            x = fa[x][i], y = fa[y][i];
    return fa[x][0]; //父节点就是lca
}
void solve() {
    int n; cin >> n;
    for (int i = 2; i <= n; i++) {
        cin >> fa[i][0];
        g[fa[i][0]].push_back(i);
    }
    dfs(1);
    int q; cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << lca(x, y) << '\n';
    }
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    /*int t; cin >> t;
    while(t--)*/
        solve();
    return 0;
}