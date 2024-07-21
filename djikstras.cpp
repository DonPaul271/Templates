
vector<vector< pair< ll, ll> > > adj;
adj.resize(n);

priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> pq;

vector<ll> distance(n,1e12);
distance[0] = 0;

        
pq.push({0, 0});
pair<ll, ll > p;

while(!pq.empty())
{
    p = pq.top(); pq.pop();
    ll curr = p.second;
    ll dist = p.first;
    
    if(dist > distance[curr])
        continue;
    
    for(int i=0; i<adj[curr].size(); ++i)
    {
        ll next = adj[curr][i].first;
        ll wt = adj[curr][i].second;
        
        if(dist + wt < distance[next] )
        {
            distance[next] = dist + wt;
            pq.push({distance[next], next});
        }
    }

}