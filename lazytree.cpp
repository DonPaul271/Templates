#include <iostream>
#include <vector>

using namespace std;

class LT {

public:

    vector<ll> tree, lazy;
    ll n;

    LT(ll n) 
    {
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);
    }

    void build(ll node, ll start, ll end, vector<ll> &arr) 
    {
        n = arr.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 0);

        if (start == end) 
        {
            tree[node] = arr[start];
        } 
        
        else 
        {
            ll mid = (start + end) / 2;
            build(2 * node + 1, start, mid, arr);
            build(2 * node + 2, mid + 1, end, arr);

            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void urange(ll node, ll start, ll end, ll l, ll r, ll val) 
    {
        if (lazy[node] != 0) 
        {
            tree[node] += (end - start + 1) * lazy[node];

            if (start != end) 
            {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end || start > r || end < l)
            return;

        if (start >= l && end <= r) 
        {
            tree[node] += (end - start + 1) * val;

            if (start != end) 
            {
                lazy[2 * node + 1] += val;
                lazy[2 * node + 2] += val;
            }
            return;
        }

        ll mid = (start + end) / 2;

        urange(2 * node + 1, start, mid, l, r, val);
        urange(2 * node + 2, mid + 1, end, l, r, val);

        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    ll qrange(ll node, ll start, ll end, ll l, ll r) 
    {
        if (lazy[node] != 0) 
        {
            tree[node] += (end - start + 1) * lazy[node];

            if (start != end) 
            {
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (start > end || start > r || end < l)
            return 0;

        if (start >= l && end <= r)
            return tree[node];

        ll mid = (start + end) / 2;
        return qrange(2 * node + 1, start, mid, l, r) + qrange(2 * node + 2, mid + 1, end, l, r);
    }
};




DRIVER CODE



int main() 
{
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int n = arr.size()

    LT lt(n);

    cout << "Sum of values in range(1, 3): " << lt.queryRange(1, 3) << endl;

    lt.updateRange(1, 5, 10);

    cout << "Sum of values in range(1, 3) after update: " << lt.queryRange(1, 3) << endl;

    return 0;
}

build(0, 0, n - 1, arr);

void updateRange(int l, int r, int diff) 
{
    urange(0, 0, n - 1, l, r, diff);
}

int queryRange(int l, int r) 
{
    return qrange(0, 0, n - 1, l, r);
}
