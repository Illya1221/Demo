#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 6e3 + 9;
const int inf = 2e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
ll dp[N][2], r[N], fa[N];
vector<int> g[N];
void dfs(int x) {
	for (auto y : g[x]) {
		//自底向上 先计算子树
		dfs(y);
		//选了x 就不能选y
		dp[x][1] += dp[y][0];
		dp[x][0] += max(dp[y][0], dp[y][1]);
	}
	dp[x][1] += r[x];
}
void solve() {
    int n; cin >> n;
	for (int i = 1; i <= n; ++ i) cin >> r[i];
	for (int i = 1; i <= n; ++ i) fa[i] = 0, g[i].clear();
	for (int i = 1; i < n; ++ i) {
		int x, y; cin >> x >> y;
		g[y].push_back(x);
		fa[x] = y;
	}
	//找到根节点
	int rt = 1;
	for (int i = 1; i <= n; ++ i) if(fa[i] == 0) rt = i;
	dfs(rt);
	cout << max(dp[rt][0], dp[rt][1]) << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}