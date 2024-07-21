ll find(vector<vector<ll>> &pre, int x1, int y1, int x2, int y2)
{
    ll tot = pre[x2][y2];
    ll a=0, b=0, c=0;

    if(x1-1>=0 && y1-1>=0)
    {
        a=pre[x1-1][y1-1];
    }

    if(x1-1>=0)
    {
        b=pre[x1-1][y2];
    }

    if(y1-1>=0)
    {
        c=pre[x2][y1-1];
    }

    tot = tot - b - c + a;
    return tot;
}


// create the 2D prefix array before using the code



vector<vector<ll>> find(vector<vector<ll>> &g)
{

    int m = g.size();
    int n = g[0].size();

    vector<ll> t(n, 0);
    vector< vector<ll> > pre(m, t);


    for(int i=0; i<g.size(); ++i)
    {
        ll sum = 0;

        for(int j=0; j<g[0].size(); ++j)
        {
            sum+=g[i];
            pre[i][j] = sum;
        }
    }


    for(int i=0; i<g[0].size(); ++i)
    {
        ll sum = 0;

        for(int j=0; j<g.size(); ++j)
        {
            sum += pre[j][i]; 
            pre[j][i] = sum;
        }
    }

    return pre;
}





