#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 2e5 + 9;
const int inf = 2e9;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
vector<int> X;
int bin(int x) {
    return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;
}
struct Node {
    int ls, rs, val;
}t[N << 5];
int n, m, idx, a[N], rt[N];
void insert(int &o, int pre, int val, int s = 1, int e = n) {
    //分配节点
    o = ++idx;
    //复刻上一版本
    t[o] = t[pre];
    //修改自身权值
    t[o].val++;
    if (s == e) return;
    //决策下一步
    int mid = (s + e) >> 1;
    if (val <= mid) insert(t[o].ls, t[pre].ls, val, s, mid);
    else insert(t[o].rs, t[pre].rs, val, mid + 1, e);
}
int queryVal(int lo, int ro, int k, int s = 1, int e = n) {
    if (s == e) return s;
    int left_sum = t[t[ro].ls].val - t[t[lo].ls].val;
    int mid = (s + e) >> 1;
    if (k <= left_sum) return queryVal(t[lo].ls, t[ro].ls, k, s, mid);
    else return queryVal(t[lo].rs, t[ro].rs, k - left_sum, mid + 1, e);
}
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        X.push_back(a[i]);
    }
    //离散化
    sort(X.begin(), X.end());
    X.erase(unique(X.begin(), X.end()), X.end());
    for (int i = 1; i <= n; i++) insert(rt[i], rt[i - 1], bin(a[i]));
    while (m--) {
        int l, r, k; cin >> l >> r >> k;
        cout << X[queryVal(rt[l - 1], rt[r], k) - 1] << '\n';
    }
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}