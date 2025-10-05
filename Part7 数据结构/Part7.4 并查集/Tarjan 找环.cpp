#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int dfn[N], low[N], stk[N], top, idx, ans;
vector<int> g[N];
bitset<N> ins;
void tarjan(int x, int fa) {
    dfn[x] = low[x] = ++idx;
    stk[++top] = x;
    ins[x] = true;
    for (auto &y : g[x]) {
        if (y == fa) continue;
        if (!dfn[y]) {
            tarjan(y, x);
            low[x] = min(low[x], low[y]);
        } else if (ins[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (low[x] == dfn[x]) {
        int cnt = 0;
        do {
            ins[stk[top]] = false;
            cnt++;
        } while (stk[top--] != x);
        if (cnt > 1) {
            ans = cnt;
            return;
        }
    }
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    tarjan(1, 0);
    cout << ans << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    /*int t; cin >> t;
    while(t--)*/
        solve();
    return 0;
}