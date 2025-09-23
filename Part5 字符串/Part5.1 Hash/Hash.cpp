#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const int N = 1e4 + 9;
const ull base = 131;
string s[N];
ull a[N], b[N], h[N], hr[N];
ull Hash(string str) {
    for (int i = 1; i <= str.size(); i++)
        h[i] = h[i - 1] * base + ull(str[i]);
    return h[str.size()];
}
ull Hashrev(string str) {
    for (int i = str.size(); i > 0; i--)
        hr[i] = h[i + 1] * base + ull(str[i]);
    return hr[1];
}
ull getHash(int l, int r) {
    return h[r] - h[l - 1] * b[r - l + 1];
}
ull getHashrev(int l, int r) {
    return h[l] - h[r + 1] * b[r - l + 1];
}
void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] = " " + s[i];
    }
    b[0] = 1;
    for (int i = 1; i <= 1e4; i++) b[i] = b[i - 1] * base;
    for (int i = 1; i <= n; i++) a[i] = Hash(s[i]);
    sort(a + 1, a + n + 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) if (a[i] != a[i - 1]) ans++;
    cout << ans;
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}