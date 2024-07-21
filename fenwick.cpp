class FT {
public:
    vector<int> tree;
    int size;

    FT(int n) 
    {
        size = n;
        tree.resize(n + 1, 0);
    }

    void build(vector<ll> &arr)
    {
        for(int i=0; i<arr.size(); ++i)
            update(i, 2*arr[i], arr[i]);
    }

    void update(int index, int value, vector<ll> &arr) 
    {
        value = value - arr[index];
        ++index;

        while (index <= size) 
        {
            tree[index] += value;
            index += index & (-index);
        }
    }

    int query(int index) 
    {
        ++index;

        int sum = 0;
        while (index > 0) 
        {
            sum += tree[index];
            index -= index & (-index);
        }
        return sum;
    }

    int rquery(int left, int right) 
    {
        return query(right) - query(left - 1);
    }
};


DRIVER 

    Ftree ft(n);
    ft.build(nums);

    index+1 always





