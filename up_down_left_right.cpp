vector<int> xm{-1, +1, 0, 0};
vector<int> ym{0, 0, -1, +1};


for(int i=0; i<4; ++i)
{
    int xn = x + xm[i];
    int yn = y + ym[i];

    if(xn>=0 && xn!=n && yn>=0 && yn!=n && vis[xn][yn]!=1)
    {

    }
}

left, right, up, down