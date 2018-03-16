// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * rearrangeLastN(ListNode<int> * l, int n) 
{
    if(n == 0)
        return l;
    int size = 0;
    ListNode<int>* t = l;
    ListNode<int>* last = NULL;
    while(t != NULL)
    {
        size++;
        if(!t->next)
            last = t;
        t = t->next;
    }
    
    int steps = size - n - 1;
    if(steps < 0)
        return l;
    t = l;
    int i = 0;
    while(i < steps)
    {
        i++;
        t = t->next;
    }
    ListNode<int>* res = t->next;
    t->next = NULL;
    last->next = l;
    return res;
    
}
