#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define ld long double
#define ull unsigned long long

ll mod = 1e9+7;

class Dset
{
    public:

    vector<int> parent;
    vector<int> size;
    vector<ll> pl;

    priority_queue< pair<int, int> > pq;

 
    Dset(int n)
    {
        parent.resize(n+1, 0);
        size.resize(n+1, 0);
        pl.resize(n+1);

        for(int i=0; i<n; ++i)
        {
            parent[i] = i;
        }
    }

    void fill(int n)
    {
        for(int i=0; i<n; ++i)
        {
            size[i] = pl[i];
            pq.push({size[i], i});
        }
    }

    int findp(int x)
    {
        if(parent[x] == x)
            return x;

        return parent[x] = findp(parent[x]);
    }

    void uni(int x, int y)
    {
        cout<<"uni"<<x<<" "<<y<<"\n";

        int xp = findp(x);
        int yp = findp(y);

        if(xp == yp)
            return;

        if(size[yp] > size[xp])
        {
            parent[xp] = yp;
            size[yp]+=size[xp];

            pq.push({ size[yp], yp });
        }

        else
        {
            parent[yp] = xp;
            size[xp]+=size[yp];

            pq.push({ size[xp], xp });
        }
    }

    void cp(int ind, int np)
    {
        int p = findp(ind);

        size[p]+=np;
        size[p]-=pl[ind];

        if(ind != p)
            size[ind] = np;

        pl[ind] = np;
        pq.push({size[p], p});
    }

    int findmx()
    {
        while(!pq.empty())
        {   
            int sz = pq.top().first;
            int ind = pq.top().second;

            cout<<"- ";
            cout<<sz<<" "<<ind<<"\n";
            cout<<size[ind]<<"\n";

            if(size[ind] != sz)
                pq.pop();
            else
                return sz;
        }

        return 0;
    }

};




int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);


    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen ("output.txt", "w", stdout);
    #endif

    int ti=1;

    ll x;

    while(ti--)
    {
        ll n,m,qs;
        ll u,v;
        cin>>n>>m>>qs;

        Dset ds(n);

        vector<ll> pl(n, 0);
        unordered_map< int, stack<int> > mp;

        set< pair<int, int> > ps;

        for(int i=0; i<n; ++i)
        {
            cin>>pl[i];
            mp[i].push(pl[i]);
        }

        ds.pl = pl;

        vector< vector<ll> > r; 
        vector< vector<ll> > q;


        for(int i=0; i<m; ++i)
        {
            cin>>u>>v;
            --u; --v;

            ps.insert({u, v});
            r.push_back({u, v});
        }

        char ch;
        ll ind, np;

        for(int i=0; i<qs; ++i)
        {
            cin>>ch;

            if(ch == 'D')
            {
                cin>>ind;
                --ind;

                ps.erase({ r[ind][0], r[ind][1]});
                q.push_back({ind});
            }

            else
            {
                cin>>ind>>np;
                --ind;

                ds.pl[ind] = np;  


                mp[ind].push(np);
                q.push_back({ind, np});
            }
        }

        pair<int, int> pr;
        ds.fill(n);

        for(auto i=ps.begin(); i != ps.end(); ++i)
        {
            pr = *i;

            int uu = pr.first;
            int vv = pr.second;

            ds.uni(uu, vv);
        }



        for(int i=0; i<ds.pl.size(); ++i)
            cout<<ds.pl[i]<<" ";

        cout<<"\n\n";

        for(int i=0; i<ds.size.size(); ++i)
            cout<<ds.size[i]<<" ";

        cout<<"\n\n";

        vector<int> ans;

        for(int i=qs-1; i>=0; --i)
        {
            int now = ds.findmx();
            ans.push_back( now );

            cout<<"\n\n++++++++++++\n\n";

            if(q[i].size() == 1)
            {
                int rind = q[i][0];

                int lll = r[rind][0];
                int rr = r[rind][1];

                ds.uni(lll, rr);
            }

            else
            {
                int ind = q[i][0];
                mp[ind].pop();

                int np = mp[ind].top();

                cout<<"np = ";
                cout<<np<<"\n";
                ds.cp(ind, np);
            }
        }

        cout<<"\n";
        reverse(ans.begin(), ans.end());

        for(int i=0; i<ans.size(); ++i)
            cout<<ans[i]<<"\n";

        cout<<"\n";
    }

    return 0;
}








