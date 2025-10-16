#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 1e5 + 9;
const int inf = 2e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
struct Node {
    ll x, w;
};
vector<Node> g[N];
ll ans, dp[N]; //dp[i]表示在i子树中，距离根最远的节点距离
void dfs(int x) {
    for(auto [y, w] : g[x]) {
        dfs(y);
        ans = max(ans, dp[x] + dp[y] + w);
        dp[x] = max(dp[x], dp[y] + w);
    }
}
void solve() {
    int n; cin >> n;
	for (int i = 2; i <= n; i++) {
        ll fa, w; cin >> fa >> w;
        g[fa].push_back({i, w});
    }
    dfs(1);
    cout << ans << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}