ListNode<int> * reverseNodesInKGroups(ListNode<int> * l, int k)
{
    ListNode<int>* head = l;
    ListNode<int>* prevHead = NULL;
    ListNode<int>* res = NULL;
    
    int size = getSize(l);
    int num = size / k;
    
    for(int j = 0; j < num; j++)
    {
        ListNode<int>* z = reverse(head, k);
        if(prevHead)
            prevHead->next = z;
        prevHead = head;
        head = head->next;
        if(j == 0)
            res = z;
    }
    return res;
}

ListNode<int>* reverse(ListNode<int>* head, int k)
{
    int i = 0;
    ListNode<int>* cur = head;
    ListNode<int>* prev = NULL;
    while(i < k)
    {
        ListNode<int>* next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
        i++;
    }
    head->next = cur;
    return prev;
}

int getSize(ListNode<int> * l)
{
    int i = 0;
    while(l != NULL)
    {
        l = l->next;
        i++;
    }
    return i;
}