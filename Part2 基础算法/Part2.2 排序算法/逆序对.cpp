#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 9;
int n, a[N], t[N];
vector<int> v;
int bin(int x) {
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}
int lowbit(int x) {
    return x & -x;
}
void update(int k, int x) {
    for (int i = k; i <= v.size(); i += lowbit(i)) t[i] += x;
}
int getsum(int k) {
    int res = 0;
    for (int i = k; i > 0; i -= lowbit(i)) res += t[i];
    return res;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v.push_back(a[i]);
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += getsum(v.size()) - getsum(bin(a[i]));
        update(bin(a[i]), 1);
    }
    cout << ans << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}