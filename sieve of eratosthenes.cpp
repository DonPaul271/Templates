vector<int> sieveOfEratosthenes(int n) {
    vector<bool> prime(n+1, true);

    for (int p = 2; p * p <= n; ++p) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    return prime;
}

+++++++++++++++++++++++++++++++++++++++

GLOBAL


bool stat = true;
vector<bool> prime;

void sieveOfEratosthenes(int n) 
{
    prime.resize(n+1, true);

    for (int p = 2; p * p <= n+1; ++p) 
    {
        if (prime[p]) 
        {
            for (int i = p * p; i <= n; i += p) 
                prime[i] = false;
        }
    }
}


INSIDE THE FUNCTION


if(stat)
{
    sieveOfEratosthenes(1e6+1);
    prime[1] = false;
    stat = false;
}




