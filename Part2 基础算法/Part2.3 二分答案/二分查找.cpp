#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 9;
int a[N];
void solve() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    while (q--) {
        int x; cin >> x;
        int l = 0, r = n;
        while(l + 1 != r) {
            int mid = (l + r) >> 1;
            if(a[mid] < x) l = mid;
            else r = mid;
        }
        if(a[r] == x) cout << a[r] << ' ';
        else cout << -1 << ' ';
    }
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}