vector<ll> prime(ll n) 
{
    vector<ll> pv;
    
    while (n % 2 == 0) 
    {
        pv.push_back(2);
        n /= 2;
    }

    for (ll i = 3; i * i <= n; i += 2)
    {
        while (n % i == 0) 
        {
            pv.push_back(i);
            n /= i;
        }
    }

    if (n > 2) 
    {
        pv.push_back(n);
    }

    return pv;
}