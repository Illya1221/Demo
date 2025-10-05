#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int dfn[N], low[N], idx, cut, es;
vector<int> g[N];
void tarjan1(int x, int fa) {
    dfn[x] = low[x] = ++idx;
    int child = 0;
    for (auto &y : g[x]) {
        //不走父亲
        if (y == fa) continue;
        //判断是否是搜索树的儿子
        if (!dfn[y]) {
            tarjan1(y, x);
            low[x] = min(low[x], low[y]);
            child += (low[y] >= dfn[x]);
        } else low[x] = min(low[x], dfn[y]);
    }
    if ((!fa && child >= 2) || (fa && child >= 1)) cut++;
} //求割点
void tarjan2(int x, int fa) {
    dfn[x] = low[x] = ++idx;
    for (auto &y : g[x]) {
        if (y == fa) continue;
        //如果y没被走过就往下走
        if (!dfn[y]) {
            //此时y是x在搜索树中的儿子
            tarjan2(y, x);
            low[x] = min(low[x], low[y]);
            //如果y回不到自身以及父亲树上
            if (low[y] > dfn[x]) es++;
        } else low[x] = min(low[x], dfn[y]);
    }
} //求割边
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan1(i, 0);
    for (int i = 1; i <= n; i++) dfn[i] = low[i] = 0;
    idx = 0;
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan2(i, 0);
    cout << cut << ' ' << es << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    /*int t; cin >> t;
    while(t--)*/
        solve();
    return 0;
}