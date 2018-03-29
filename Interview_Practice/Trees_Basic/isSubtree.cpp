//
// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };
vector<Tree<int>*> v;
bool isSubtree(Tree<int> * t1, Tree<int> * t2) 
{
    if(!t2 || (!t2 && !t1))
        return true;
    if(!t1 || !t2)
        return false;
    
    getDepth(t1, getDepth(t2, -1));
    
    for(auto& node : v)
        if(isSame(node, t2))
            return true;
    
    return false;
}

int getDepth(Tree<int>* root, int depth)
{
    if(!root)
        return -1;
    
    int d = max(getDepth(root->left, depth), getDepth(root->right, depth)) + 1;
    
    if(d == depth)
        v.push_back(root);
    
    return d;
}

bool isSame(Tree<int>* tree1, Tree<int>* tree2)
{
    if(!tree1 && !tree2)
        return true;
    if(!tree1 || !tree2 || tree1->value != tree2->value)
        return false;
    
    return isSame(tree1->left, tree2->left) && isSame(tree1->right, tree2->right);
}
