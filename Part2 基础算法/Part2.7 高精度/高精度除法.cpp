#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 9;
ll a[N], c[N];
void solve() {
    string s; ll b;
    cin >> s >> b;
    reverse(s.begin(), s.end());
    int len = s.size();
    for (int i = 0; i < len; i++) a[i] = s[i] - '0';
    for (int i = len - 1; i >= 0; i--) {
        a[i] += a[i + 1] * 10;
        c[i] = a[i] / b;
        a[i] %= b;
    }
    while (len > 1 && !c[len - 1]) len--;
    for (int i = len - 1; i >= 0; i--) cout << c[i];
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}