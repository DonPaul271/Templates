
int ask(int x, int y)
{
    cout<<"? "<<x<<" "<<y<<"\n"; 
    cout.flush();

    int res;
    cin>>res;

    return res;
}


void ans(int x, int y)
{
    cout<<"! "<<x<<" "<<y<<"\n"; 
    cout.flush();
}