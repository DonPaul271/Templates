
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges, vector<vector<int>> &adj) {
    

    vis[node] = 1;
    tin[node] = low[node] = t;
    t++;

    for (auto it : adj[node]) 
    {
        if (it == parent) continue;

        if (vis[it] == 0) 
        {
            dfs(it, node, vis, adj, tin, low, bridges);
            low[node] = min(low[it], low[node]);

            if (low[it] > tin[node]) 
            {
                bridges.push_back({it, node});
            }
        }


        else 
        {
            low[node] = min(low[node], low[it]);
        }
    }
}




bridges will have all the bridges
