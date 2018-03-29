//
// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
bool hasPathWithGivenSum(Tree<int> * t, int s) 
{
    if(t == NULL)
        return s == 0;
    if(t->left == NULL && t->right == NULL) // it is a leaf
    {
        cout << "here";
        if(t->value == s)
            return true;
        else 
            return false;
    }
    return t->left && hasPathWithGivenSum(t->left, s - t->value) ||
           t->right && hasPathWithGivenSum(t->right, s - t->value);
}
