#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int dfn[N], low[N], stk[N], top, idx;
int col[N], tot, cnt[N];
vector<int> g[N];
bitset<N> ins;
//tarjan的本质是dfs
void tarjan(int x) {
    //初始化dfn和low
    dfn[x] = low[x] = ++idx;
    //入栈并标记
    stk[++top] = x;
    ins[x] = true;
    //遍历所有儿子
    for (auto &y : g[x]) {
        //判断是否是回点
        if (!dfn[y]) {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        } else if (ins[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    //收拢
    if (low[x] == dfn[x]) {
        //新开一个颜色
        tot++;
        do {
            //染色
            col[stk[top]] = tot;
            cnt[tot]++;
            //取消标记
            ins[stk[top]] = false;
        } while (stk[top--] != x);
    }
}
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
    vector<int> v;
    for (int i = 1; i <= tot; i++) if (cnt[i] > 1) v.push_back(cnt[i]);
    if (!v.empty()) {
        sort(v.begin(), v.end());
        for (auto &i : v) cout << i << ' ';
    } else cout << -1;
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    /*int t; cin >> t;
    while(t--)*/
        solve();
    return 0;
}