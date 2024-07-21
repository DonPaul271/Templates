



// function returns the centre or centres of the tree(it will be either 1  or 2)

vector<string> find(vector<vector<int>> &adj, vector<int> &in)
{
    vector<int> leaf;
    vector<int> par;

    for(int i=1; i<=n; ++i)
    {
        if(in[i] == 1)
            leaf.push_back(i);
        else
            par.push_back(i);
    }

    int rem = n - leaf.size();

    vector<int> tleaf;
    vector<int> vis(n+1, 0);

    while(rem > 2)
    {

        for(int j=0; j<leaf.size(); ++j)
        {
            int curr = leaf[j];

            vis[curr] = 1;

            for(int i=0; i<adj[curr].size(); ++i)
            {   
                int now = adj[curr][i];

                if(in[now] > 1)
                {
                    in[now]-=1;

                    if(in[now] == 1)
                        tleaf.push_back(now);
                }
            }
        }



        leaf = tleaf;
        tleaf.clear();

        rem = rem - leaf.size();
    }


    for(int j=0; j<leaf.size(); ++j)
    {
        int curr = leaf[j];

        vis[curr] = 1;

        for(int i=0; i<adj[curr].size(); ++i)
        {   
            int now = adj[curr][i];

            if(in[now] > 1)
            {
                in[now]-=1;

                if(in[now] == 1)
                    tleaf.push_back(now);
            }
        }
    }

    vector<int> centre;

    for(int i=1; i<=n; ++i)
    {
        if(vis[i] == 0)
        {
            centre.push_back(i);

        }
    }

    return centre;
}


//-----------

THIS CODE IS FOR TREES. FOR DIRECTED GRAPHS MAKE INDEGREE 0 NOT 1

vector<int> in(n+1, 0);
vector<vector<int>> adj;

adj.resize(n+1);

for(int i=0; i<n-1; ++i)
{   
    cin>>u>>v;

    in[u]+=1;
    in[v]+=1;

    adj[u].push_back(v);
    adj[v].push_back(u);
}  