
//a power b

ll find(ll a ,ll b) 
{
    ll res = 1;

    while(b > 0)
    {
        if(b&1) 
        {
            res = res * a;
            res%=mod;
        }

        a = a * a;
        a%=mod;
        b = b >> 1;
    }

    return res;
}