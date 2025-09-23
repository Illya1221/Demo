#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 3e7 + 9;
char s[N];
int p[N];
void solve() {
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    for (int i = 2 * n + 1; i > 0; i--) {
        if (i & 1) s[i] = '#';
        else s[i] = s[i >> 1];
    }
    s[0] = '$', s[2 * n + 2] = '^';
    int c = 0, r = 0;
    for (int i = 1; i <= 2 * n + 1; i++) {
        p[i] = i < r ? min(p[2 * c - i], r - i) : 1;
        while (s[i + p[i]] == s[i - p[i]]) p[i]++;
        if (i + p[i] > r) c = i, r = i + p[i];
    }
    int ans = 0;
    for (int i = 1; i <= 2 * n + 1; i++) ans = max(ans, p[i] - 1);
    printf("%d", ans);
    return;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while (t--) solve();
    return 0;
}