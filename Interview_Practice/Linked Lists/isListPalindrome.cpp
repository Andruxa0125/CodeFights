// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
bool isListPalindrome(ListNode<int> * l) 
{
    if(l == NULL || l->next == NULL)
        return true;
    
    ListNode<int>* slow = l;
    ListNode<int>* fast = l;
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    // slow should point to the middle now
    
    ListNode<int>* cur = slow;
    ListNode<int>* next = cur->next;
    cur->next = NULL;
    while(next != NULL)
    {
        ListNode<int>* t = next->next;
        next->next = cur;
        cur = next;
        next = t;
    }
    // current points to the last node
    
    ListNode<int>* last = cur;
    ListNode<int>* first = l;
    while(first != NULL && last != NULL)
    {
        if(first->value != last->value)
            return false;
        first = first->next;
        last = last->next;
    }
    return true;
}
