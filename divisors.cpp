vector<ll> divisor(ll n) {

    vector<ll> divisors;
    

    for (ll i = 1; i * i <= n; i++) 
    {
        if (n % i == 0) 
        {
            if (n / i != i) 
                divisors.push_back(n / i);

            divisors.push_back(i);
        }
    }

    return divisors;
}