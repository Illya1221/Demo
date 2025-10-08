#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e3 + 5;
int n, m;
struct Node {
    int x, w;
};
vector<Node> g[N];
bitset<N> vis;
int d[N], cnt[N];
bool spfa(int st) {
    memset(d, 0x3f, sizeof d);
    d[st] = 0;
    queue<int> q;
    q.push(st);
    while (!q.empty()) {
        int x = q.front(); q.pop();
        vis[x] = false;
        for (auto &[y, w] : g[x]) {
            if (d[y] > d[x] + w) {
                d[y] = d[x] + w;
                cnt[y] = cnt[x] + 1;
                if (cnt[y] > n) return false;
                if (!vis[y]) {
                    q.push(y);
                    vis[y] = true;
                }
            }
        }
    }
    return true;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        g[0].push_back({i, 0});
    }
    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[b].push_back({a, c});
    }
    if (spfa(0)) {
        for (int i = 1; i <= n; i++) {
            cout << d[i] << ' ';
        }
    } else {
        cout << "NO";
    }
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    /*int t; cin >> t;
    while(t--)*/
        solve();
    return 0;
}