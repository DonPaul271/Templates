vector<int> find(vector<vector<int>> &adj, vector<int> &in)
{
    vector<int> ans;
    vector<int> leaf;

    for(int i=0; i<in.size(); ++i)
    {
        if(in[i] == 0)
            leaf.push_back(i);
    }

    vector<int> tleaf;

    while(leaf.size() != 0)
    {
        for(int i=0; i<leaf.size(); ++i)
        {
            ans.push_back(leaf[i]);
        }
        
        for(int j=0; j<leaf.size(); ++j)
        {
            int curr = leaf[j];

            for(int i=0; i<adj[curr].size(); ++i)
            {   
                int now = adj[curr][i];

                if(in[now] > 0)
                {
                    in[now]-=1;

                    if(in[now] == 0)
                        tleaf.push_back(now);
                }
            }
        }

        leaf = tleaf;
        tleaf.clear();
    }

    for(int i=0; i<leaf.size(); ++i)
    {
        ans.push_back(leaf[i]);
    }

    return ans;
}