ll modp(ll x, ll y, ll p) 
{ 
    ll res = 1;   
 
    x = x % p; 
             
  
    if (x == 0) return 0;
 
    while (y > 0) 
    { 
       
        if (y & 1) 
            res = (res*x) % p; 
 
        y = y>>1;
        x = (x*x) % p; 
    } 
    
    return res; 
}


// modp(base, power, mod)


ll modp(ll x, ll y) 
{ 
    ll res = 1;   
 
             
  
    if (x == 0) return 0;
 
    while (y > 0) 
    { 
       
        if (y & 1) 
            res = res*x; 
 
        y = y>>1;
        x = (x*x); 
    } 
    
    return res; 
}
