裴蜀定理

对于不定方程 ax + by = c (其中a, b, c已知)
当且仅当 gcd(a, b) | c 时, x, y 有整数解

exgcd

对于不定方程 ax + by = c (其中a, b, c已知)
先求出 ax + by = gcd(a, b) = d 的一个特解 x0, y0
再将特解扩大倍数 c / d 得到 ax + by = c 的特解
再通过 x = x0 % (b / d)  可以得到 x 的最小非负整数解
形式化的说 : 假设 x 的最小非负整数解为 x1, 特解为 x0, 则有
x1 = (x0 * c / d) % (b / d)

ll mo(ll x, ll p) {
    //x为负整数时也能取到正整数的模
    return (x % p + p) % p;
}

ll exgcd(ll a, ll b, ll &x, ll &y) {
    if (!b) return x = 1, y = 0, a;
    ll d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
//如果 c % d != 0 则无正整数解
//若 a, b 可能为负, 则传入abs算出 -x, -y 后特判输出即可

Lucas定理

C(n, m) % p = C(n / p, m / p) * C(n % p, m % p);

ll lucas(ll n, ll m, ll p) {
    if (!m) return 1;
    return lucas(n / p, m / p, p) * C(n % p, m % p, p) % p;
}