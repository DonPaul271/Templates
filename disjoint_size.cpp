class Dset
{
    public:

    vector<int> parent;
    vector<int> size;

    Dset(int n)
    {
        parent.resize(n+1, 0);
        size.resize(n+1, 0);

        for(int i=0; i<n; ++i)
        {
            parent[i] = i;
            size[i] = 1;
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
        int xp = findp(x);
        int yp = findp(y);

        if(xp == yp)
            return;

        if(size[yp] > size[xp])
        {
            parent[xp] = yp;
            size[yp]+=size[xp];
        }

        else
        {
            parent[yp] = xp;
            size[xp]+=size[yp];
        }
    }
};