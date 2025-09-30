#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e5 + 9;
vector<int> v;
void Erichsen(int n) {
    bitset<N> vis;
    vis[0] = vis[1] = true;
    for (int i = 2; i <= n; i++) {
        if (vis[i]) continue;
        for (int j = i * i; j <= n; j += i) vis[j] = true;
    }
    v.push_back(1);
    for (int i = 2; i <= n; i++) if (!vis[i]) v.push_back(i);
}
map<int, int> sg;
int getSG(int x) {
    if (!x) return 0;
    if (sg.count(x)) return sg[x];
    unordered_set<int> st;
    for (const auto &i : v) {
        if (x >= i) st.insert(getSG(x - i));
        else break;
    }
    for (int i = 0; ; i++) {
        if (!st.count(i)) return sg[x] = i;
    }
} //当x范围较大时,先用正常的SG函数打表求出周期,再将SG函数改成 return x % T;
int a[N];
void solve() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans ^= getSG(a[i]);
    }
    cout << (ans ? "YES" : "NO") << '\n';
    return;
}
int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1; //cin >> t;
    Erichsen(1000);
    while(t--) solve();
    return 0;
}