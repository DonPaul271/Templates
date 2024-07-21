
// to call use nCrMod(n,r,mod)



// avoid factorialmod function for faster calculation
// just precompute required factorials

ll factorialMod(ll n, ll m) {
    ll fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact = (fact * i) % m;
    }
    return fact;
}

ll modInverse(ll a, ll m) {
    ll m0 = m, t, q;
    ll x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

ll nCrMod(ll n, ll r, ll m) {
    ll numerator = factorialMod(n, m);
    ll denominator = (factorialMod(r, m) * factorialMod(n - r, m)) % m;
    ll denInverse = modInverse(denominator, m);
    ll result = (numerator * denInverse) % m;
    
    return result;
}
