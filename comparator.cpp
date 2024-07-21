struct Comapre
{
    bool operator() ( tuple<int, int, int> &a, tuple<int, int, int> &b)
    {
        return get<0>(a) > get<0>(a);
    }
};



SMALLEST HAS HIGHEST PRIORITY