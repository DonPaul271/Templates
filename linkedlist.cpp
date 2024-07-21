struct Node 
{
    int val;
    int key;

    Node* next;
    Node* prev;
};


struct DLL
{
    public:

    Node* head = new Node();
    Node* tail = new Node();

    DLL()
    {
        head->prev = NULL;
        head->next = tail;

        tail->prev = head;
        tail->next = NULL;

        head->val = -1;
        tail->val = -1;
    }

    void remove(Node* curr)
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    } 

    void add(Node* curr)
    {
        tail->prev->next = curr;
        curr->prev =  tail->prev;

        tail->prev = curr;
        curr->next = tail; 
    }

};