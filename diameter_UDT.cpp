int find(vector<int> &in, vector<vector<int>> &adj)
{
    vector<int> leaf;
    vector<int> tleaf;

    vector<int> vis(in.size(), 0);

    for(int i=0; i<in.size(); ++i)
    {
        if(in[i] == 1)
        {
            leaf.push_back(i);
            vis[i] = 1;
        }
    }

    int rem = in.size() - leaf.size();
    int cnt = 0;

    if(rem > 0)
        cnt++;

    while(1)
    {
        for(int i=0; i<leaf.size(); ++i)
        {   
            int curr = leaf[i];

            for(int j=0; j<adj[curr].size(); ++j)
            {
                int next = adj[curr][j];

                if(vis[next] == 0)
                {
                    in[next]-=1;

                    if(in[next] == 1)
                    {
                        tleaf.push_back(next);
                        vis[next] = 1;
                    }
                }
            }
        }

        leaf = tleaf;
        tleaf.clear();

        rem = rem - leaf.size();

        if(rem==0)
            break;

        ++cnt;
    }

    if(leaf.size() == 1)
        return cnt*2;

    else
        return cnt*2+1;
}
