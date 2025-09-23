#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9;
char s[N], t[N];
int nxt[N];
void solve() {
    scanf("%s%s", s + 1, t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    s[n + 1] = '#', t[m + 1] = '$';
    nxt[1] = 0;
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && t[i] != t[j + 1]) j = nxt[j];
        if (t[i] == t[j + 1]) j++;
        nxt[i] = j;
    }
    for (int i = 1, j = 0; i <= n; i++) {
        while (j && s[i] != t[j + 1]) j = nxt[j];
        if (s[i] == t[j + 1]) j++;
        if (j == m) printf("%d\n", i - j + 1);
    }
    for (int i = 1; i <= m; i++) printf("%d ", nxt[i]);
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}