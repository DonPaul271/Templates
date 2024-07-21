struct Node
{
    Node* links[2];
    int cnt = 1;

    bool contains(int num)
    {
        return links[num] != NULL;
    }

    void createLink(int num, Node* node)
    {
        links[num] = node;
    }

    Node* get(int num)
    {
        return links[num];
    }

};

class Trie
{
    public:
    Node* root;
    Node* next;
    int tot;

    Trie()
    {
        root = new Node();
        tot = 0;
    }

    void insert(int num)
    {
        ++tot;
        Node* curr = root;
        int c;

        for(int i=31; i>=0; --i)
        {
            c = (num>>i)&1;

            if( !curr->contains(c) )
                curr->createLink(c, new Node());

            else
            {
                next = curr->get(c); 
                next->cnt+=1;
            }

            curr = curr->get(c);  
        }
    }

    void remove(int num)
    {
        ++tot;
        Node* curr = root;
        int c;

        for(int i=31; i>=0; --i)
        {
            c = (num>>i)&1;

            next = curr->get(c); 
            next->cnt-=1;

            curr = curr->get(c);  
        }
    }

    int check(int num)
    {
        Node* curr = root;

        int c;
        int res = 0;

        for(int i=31; i>=0; --i)
        {
            c = (num>>i)&1;

            if(curr->contains(1-c))
            {
                next = curr->get(1-c);

                if(next->cnt > 0)
                {
                    res += 1<<i;
                    curr = curr->get(1-c);
                }

                else
                    curr = curr->get(c);
            }

            else
                curr = curr->get(c);
        }

        return res;
    }

};



// Trie* tr = new Trie;
// pasing to function as find(Trie* &tr)