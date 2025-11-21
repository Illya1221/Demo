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
const ld EPS = 1e-12;
const ld PI = acos(-1);
struct Point {
    ld x, y;
    Point() : x{0}, y{0} {}
    Point(ld _x, ld _y) : x{_x}, y{_y} {}
};
ld dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}
ld cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}
Point operator + (Point a, Point b) {
    return Point(a.x + b.x, a.y + b.y);
}
Point operator - (Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y);
}
ld dist(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
auto getHull(vector<Point> p) {
    sort(p.begin(), p.end(),
        [&](auto a, auto b) {
            return a.x < b.x || (a.x == b.x && a.y < b.y);
    });
    vector<Point> hi, lo;
    for (auto p : p) {
        while (hi.size() > 1 && cross(hi.back() - hi[hi.size() - 2], p - hi.back()) >= 0) {
            hi.pop_back();
        }
        while (!hi.empty() && hi.back().x == p.x) {
            hi.pop_back();
        }
        hi.push_back(p);
        while (lo.size() > 1 && cross(lo.back() - lo[lo.size() - 2], p - lo.back()) <= 0) {
            lo.pop_back();
        }
        if (lo.empty() || lo.back().x < p.x) {
            lo.push_back(p);
        }
    }
    ld res = 0.0;
    for (int i = 1; i < hi.size(); i++) {
        res += dist(hi[i - 1], hi[i]);
    }
    for (int i = 1; i < lo.size(); i++) {
        res += dist(lo[i - 1], lo[i]);
    }
    res += dist(hi.front(), lo.front());
    res += dist(hi.back(), lo.back());
    return res;
    // return make_pair(hi, lo);
}
Point rotate(Point a, ld t) {
    ld c = cos(t), s = sin(t);
    return Point(a.x * c - a.y * s, a.x * s + a.y * c);
}
void solve() {
    int n;
    cin >> n;
    ld a, b, r;
    cin >> b >> a >> r;
    a /= 2.0, b /= 2.0;
    vector<Point> p;
    for (int i = 1; i <= n; i++) {
        ld x, y, t;
        cin >> x >> y >> t;
        x += EPS, y += EPS, t += EPS;
        Point p0 = Point(x, y);
        p.push_back(rotate(Point(a - r, b - r), t) + p0);
        p.push_back(rotate(Point(a - r, r - b), t) + p0);
        p.push_back(rotate(Point(r - a, b - r), t) + p0);
        p.push_back(rotate(Point(r - a, r - b), t) + p0);
    }
    ld res = getHull(p);
    res += 2 * PI * r;
    cout << fixed << setprecision(2) << res;
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