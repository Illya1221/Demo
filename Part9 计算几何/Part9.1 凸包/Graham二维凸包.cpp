#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int N = 1e5 + 9;
const int inf = 0x3f3f3f3f;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 998244353;
const int MOD = 1e9 + 7;
const ld EPS = 1e-7;
struct Point {
    ld x, y;
};
ld calc(Point a1, Point a2, Point b1, Point b2) {
    // 检查叉积是否大于0,如果是那么a逆时针旋转到b
    return (a2.x - a1.x) * (b2.y - b1.y) - (a2.y - a1.y) * (b2.x - b1.x);
}
Point fir;
ld dis(Point u, Point v) {
    return sqrt((u.x - v.x) * (u.x - v.x) + (u.y - v.y) * (u.y - v.y));
}
bool cmp(const Point& u, const Point& v) {
    ld res = calc(fir, u, fir, v);
    if (res > 0) {
        return true;
    }
    if (res == 0) {
        return dis(fir, u) < dis(fir, v);
    }
    return false;
}
void solve() {
    int n;
    cin >> n;
    vector<Point> p(n + 1), s(n + 2);
    Point tmp;
    for (int i = 1; i <= n; i++) {
        cin >> p[i].x >> p[i].y;
        // 保证p[1]的x和y坐标都是最小的
        if (i != 1 && p[i].y < p[1].y) {
            tmp.x = p[1].x, tmp.y = p[1].y;
            p[1].x = p[i].x, p[1].y = p[i].y;
            p[i].x = tmp.x, p[i].y = tmp.y;
        } else if (i != 1 && p[i].y == p[1].y && p[i].x < p[1].x) {
            tmp.x = p[1].x, tmp.y = p[1].y;
            p[1].x = p[i].x, p[1].y = p[i].y;
            p[i].x = tmp.x, p[i].y = tmp.y;
        }
    }
    fir.x = p[1].x, fir.y = p[1].y;
    sort(p.begin() + 2, p.end(), cmp);
    // 最低点一定在凸包里
    s[1] = p[1];
    int top = 1;
    for (int i = 2; i <= n; i++) {
        while (top > 1 && calc(s[top - 1], s[top], s[top], p[i]) <= 0) {
            top--;
        }
        s[++top] = p[i];
    }
    // 最后一个点回到凸包起点
    s[++top] = p[1];
    ld ans = 0.0;
    for (int i = 2; i <= top; i++) {
        ans += dis(s[i - 1], s[i]);
    }
    cout << fixed << setprecision(2) << ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}