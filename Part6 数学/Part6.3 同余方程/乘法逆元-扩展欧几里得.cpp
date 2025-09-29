#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e9 + 9;
int n, M;
//x为负整数时也能取到正整数的模
ll mo(int x, int M) {
    return (x % M + M) % M;
}
//求 ax + by = gcd(a, b) = d 的特解 x0
//则 ax + by = c 的最小非负整数解 x1 = (x0 * c / d) % (b / d)
//如果 c % d != 0 则无正整数解
//若 a, b 可能为负, 则传入abs算出 -x, -y 后特判输出即可
ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
void solve() {
    cin >> n >> M; ll x = 1, y = 0;
    for (int i = 1; i <= n; i++) {
        exgcd(i, M, x, y);
        cout << mo(x, M) << '\n';
    }
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}