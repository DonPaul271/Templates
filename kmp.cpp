-1 indexed (0 below)


vector<int> find(string s)
{    
    int index = 0;
    vector<int> res(s.length(), -1);
 
    for(int i=1; i<s.length(); )
    {
        if(s[i] == s[index])
        {
            ++index;
            res[i] = index-1 ;
            ++i;
        }

        else
        {
            if(index != 0)
                index = res[index - 1] + 1;

            else
            {
                res[i] = index - 1;
                ++i;
            }
        }
    }

    return res;
}


//--------------------------------------



for(int i=0; i<s.size(); ++i)
{
    if( a[p+1] == s[i] )
        ++p;

    else
    {
        while(p!=-1)
        {
            p = a1[p];

            if(a[p+1] == s[i])
            {
                ++p;
                break;
            }
        }
    }

    if(p == l-1)
        return i - l + 1;
}





//=================================

0 indexed 


vector<int> find(string s)
{    
    int index = 0;
    vector<int> res(s.length(), -1);
 
    for(int i=1; i<s.length(); )
    {
        if(s[i] == s[index])
        {
            ++index;
            res[i] = index-1 ;
            ++i;
        }

        else
        {
            if(index != 0)
                index = res[index - 1] + 1;

            else
            {
                res[i] = index - 1;
                ++i;
            }
        }
    }

    for(int i=0; i<res.size(); ++i)
        res[i]++;

    return res;
}




//++++++++++++++++++

KMP CONTINOUS USING 0 NOT -1;


while( pa < a.length() )
{
    char ch = a[pa];

    if(a[pa] == b[pb])
    {
        ++pb;
    }

    else
    {
        while(pb!=0)
        {
            pb = arr[pb-1];

            if(b[pb] == ch)
            {
                ++pb;
                break;
            }
        }
    }

    if(pb == b.length())
    {
        pb = arr[pb-1];
        ++ans;
    }

    ++pa;
}




