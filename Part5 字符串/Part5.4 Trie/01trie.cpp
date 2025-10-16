#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 9;
const int inf = 2e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
struct Node {
    int val, son[2];
}t[N * 32];
int idx;
void insert(int x) {
    int o = 0;
    for (int i = 30; i >= 0; i--) {
        //取出x的第i位
        int y = x >> i & 1;
        int &u = t[o].son[y];
        if (!u) u = ++idx;
        o = u;
    }
}
int getMax(int x) {
    int o = 0, res = 0;
    for (int i = 30; i >= 0; i--) {
        int y = x >> i & 1;
        int u = t[o].son[y], v = t[o].son[!y];
        //尽可能走v
        if (v) o = v, res |= (1 << i);
        else o = u;
    }
    return res;
}
void solve() {
    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    insert(a[1]);
    int ans = a[1] ^ a[2];
    for (int i = 2; i <= n; i++) {
        ans = max(ans, getMax(a[i]));
        insert(a[i]);
    }
    cout << ans << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}