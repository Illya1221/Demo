Lucas定理

C(n, m) % p = C(n / p, m / p) * C(n % p, m % p);

ll lucas(ll n, ll m, ll p) {
    if (!m) return 1;
    return lucas(n / p, m / p, p) * C(n % p, m % p, p) % p;
}