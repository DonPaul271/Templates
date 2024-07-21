

ll gcd(ll a, ll b) 
{
    if (b == 0)
        return a;

    return gcd(b, a % b);
}


int vgcd( vector<ll> &arr) 
{
    int result = arr[0];

    for (int i = 1; i < arr.size(); i++) 
    {
        result = gcd(arr[i], result);

        if (result == 1) 
            return 1;
    }

    return result;
}