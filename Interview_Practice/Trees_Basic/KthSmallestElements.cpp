//
// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
int counter = -1;
int result = 0;
int kthSmallestInBST(Tree<int> * t, int k) 
{
    helper(t, k);
    return result;
}

int helper(Tree<int> * t, int k) 
{
    if(!t)
        return 0;
    
    helper(t->left, k);
    
    if(counter != - 1)
    {
        counter++;
    }
    
    if(counter == -1 && t->left == NULL)
    {
        counter = 1;
    }
    
    if(counter == k)
    {
        result = t->value;
        return t->value;
    }
    
    helper(t->right, k);
}
