// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * mergeTwoLinkedLists(ListNode<int> * l1, ListNode<int> * l2) 
{
    
    ListNode<int>* res = new ListNode<int>(-999);
    ListNode<int>* cur;
    ListNode<int>* prev = res;
    while(l1 != NULL && l2 != NULL)
    {
        if(l1->value <= l2->value)
        {
            cur = new ListNode<int>(l1->value);
            l1 = l1->next;
        }
        else
        {
            cur = new ListNode<int>(l2->value);
            l2 = l2->next;
        }
        prev->next = cur;
        prev = cur;
    }
    while(l1 != NULL)
    {
        cur = new ListNode<int>(l1->value);
        prev->next = cur;
        prev = cur;
        l1 = l1->next;
    }
    while(l2 != NULL)
    {
        cur = new ListNode<int>(l2->value);
        prev->next = cur;
        prev = cur;
        l2 = l2->next;
    }
    prev->next = NULL;
    return res->next;
}
