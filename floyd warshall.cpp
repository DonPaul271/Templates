
for (int k = 0; k < n; ++k) 
{
    for (int i = 0; i < n; ++i) 
    {
        for (int j = 0; j < n; ++j) 
        {
            if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX &&dist[i][k] + dist[k][j] < dist[i][j]) 
            {
                dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
}





