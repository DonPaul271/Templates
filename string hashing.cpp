
int n = 1e6+1;

ll b1 = 26;
ll b2 = 52;

ll m1 = 1073741901;
ll m2 = 1073742003;

ll c1=1, c2=1;

vector<ll> exp1(n, 0);
vector<ll> exp2(n, 0);


exp1[0] = c1;
exp2[0] = c2;

for(int i=1; i<n; ++i)
{
    c1 = c1*b1;
    c2 = c2*b2;

    c1%=m1;
    c2%=m2;

    exp1[i] = c1;
    exp2[i] = c2;
}





























