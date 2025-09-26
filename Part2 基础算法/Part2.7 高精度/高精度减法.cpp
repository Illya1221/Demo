#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e4 + 9;
int a[N], b[N], c[N];
void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int len1 = s1.size(), len2 = s2.size();
    if ((s1 < s2 && len1 == len2) || len1 < len2) {
        cout << '-';
        swap(s1, s2);
        swap(len1, len2);
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    for (int i = 0; i < len1; i++) a[i] = s1[i] - '0';
    for (int i = 0; i < len2; i++) b[i] = s2[i] - '0';
    int len = max(len1, len2);
    for (int i = 0; i < len; i++) {
        if (a[i] < b[i]) {
            a[i + 1]--;
            a[i] += 10;
        }
        c[i] = a[i] - b[i];
    }
    while (len > 1 && !c[len - 1]) len--;
    for (int i = len - 1; i >=0; i--) cout << c[i];
    return;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t = 1; //cin >> t;
    while(t--) solve();
    return 0;
}