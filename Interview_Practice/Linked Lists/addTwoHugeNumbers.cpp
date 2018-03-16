// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) 
{
    ListNode<int>* result = new ListNode<int>(0);
    ListNode<int>* working = result;
    ListNode<int>* big = a;
    ListNode<int>* small = b;
    
    int sizeB = size(a);
    int sizeS = size(b);
    
    if(sizeB < sizeS)
    {
        ListNode<int>* t = big;
        big = small;
        small = t;
    }
    // advance to the end
    big = reverse(big);
    small = reverse(small);
    
    ListNode<int>* curB = big;
    ListNode<int>* curS = small;
    int var1 = 0;
    int var2 = 0;
    int remainder = 0;
    while(curB != NULL || remainder != 0)
    {
        var1 = 0;
        var2 = 0;
        if(curB != NULL)
            var1 = curB->value;
        if(curS != NULL)
        {
            var2 = curS->value;
        }
        
        int res = var1 + var2 + remainder;
        remainder = 0;
        
        if(res > 9999)
        {
            remainder = 1;
            res = res % 10000;
        }
        working->value = res;
        working->next = new ListNode<int>(0);
        working = working->next;
        
        if(curB != NULL)
            curB = curB->next;
        if(curS != NULL)
            curS = curS->next;
    }
    ListNode<int>* w = result;
    while(w && w->next && w->next->next)
        w = w->next;
    w->next = NULL;
    return reverse(result);
}

int size(ListNode<int>* head)
{
    int size = 0;
    while(head != NULL)
    {
        size++;
        head = head->next;
    }
    return size;
}

ListNode<int>* reverse(ListNode<int>* head) // reverses and returns the size
{
    ListNode<int>* prev = NULL;
     while(head)
    {
        ListNode<int>* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}
