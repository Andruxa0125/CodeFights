// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * removeKFromList(ListNode<int> * l, int k) 
{
    ListNode<int>* start = l;
    ListNode<int>* prev = new ListNode<int>();
    prev->next = start;
    ListNode<int>* result = prev;
    while(start != NULL)
    {
        if(start->value == k)
        {
            prev->next = start->next;
            start = prev->next;
        }
        else
        {
            prev = start;
            start = start->next;
        }
    }
    return result->next;
}
