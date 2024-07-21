class SGT 
{
public:
    vector<ll> seg;

    SGT(ll n) 
    {
        seg.resize(4 * n + 1);
    }

    void build(ll ind, ll low, ll high, vector<ll> &arr) 
    {
        if (low == high) 
        {
            seg[ind] = arr[low];
            return;
        }

        ll mid = (low + high) / 2;

        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    ll query(ll ind, ll low, ll high, ll l, ll r) 
    {
        if (r < low || high < l) 
            return LLONG_MAX;

        if (low >= l && high <= r) 
            return seg[ind];

        ll mid = (low + high) >> 1;
        ll left = query(2 * ind + 1, low, mid, l, r);
        ll right = query(2 * ind + 2, mid + 1, high, l, r);

        return min(left, right);
    }

    void update(ll ind, ll low, ll high, ll i, ll val) 
    {
        if (low == high) 
        {
            seg[ind] = val;
            return;
        }

        ll mid = (low + high) >> 1;

        if (i <= mid) 
            update(2 * ind + 1, low, mid, i, val);
        else 
            update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};



DRIVER

    SGT st(n);
    st.build(0, 0, n-1, nums);








class SGT 
{
    
public:

	vector<ll> seg;

    SGT(int n) 
    {
        seg.resize(4 * n + 1);
    }

    void build(int ind, int low, int high, vector<ll> &arr) 
    {
        if (low == high) 
        {
            seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) / 2;

        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r) 
    {

        if (r < low || high < l) 
            return INT_MAX;

        if (low >= l && high <= r) 
            return seg[ind];

        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r);
        int right = query(2 * ind + 2, mid + 1, high, l, r);

        return min(left, right);
    }
    void update(int ind, int low, int high, int i, int val) 
    {
        if (low == high) 
        {
            seg[ind] = val;
            return;
        }

        int mid = (low + high) >> 1;

        if (i <= mid) 
            update(2 * ind + 1, low, mid, i, val);

        else 
            update(2 * ind + 2, mid + 1, high, i, val);

        seg[ind] = min(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

