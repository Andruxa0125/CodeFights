//
// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
bool isTreeSymmetric(Tree<int> * t)
{
    if(!t)
        return true;
    queue<Tree<int>*> q;
    q.push(t->left);
    q.push(t->right);
    while(!q.empty())
    {
        Tree<int> * left = q.front(); q.pop();
        Tree<int> * right = q.front(); q.pop();
        
        if(left == NULL && right == NULL)
        {
            continue;
        }
        if((left && !right) ||
           (!left && right))
            return false;
        if(left->value != right->value)
            return false;
        q.push(left->left);
        q.push(right->right);
        q.push(left->right);
        q.push(right->left);
    }
    return true;
}
