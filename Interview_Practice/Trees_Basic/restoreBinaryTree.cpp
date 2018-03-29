//
// Definition for binary tree:
// template<typename T>
// struct Tree {
//   Tree(const T &v) : value(v), left(nullptr), right(nullptr) {}
//   T value;
//   Tree *left;
//   Tree *right;
// };

unordered_map<int, int> map;

Tree<int> * restoreBinaryTree(std::vector<int> inorder, std::vector<int> preorder) 
{
    for(int i = 0; i < inorder.size(); i++)
    {
        map[inorder[i]] = i;
    }
    return helper(inorder, 0, inorder.size() - 1, preorder, 0, preorder.size() - 1);
}

Tree<int> * helper(std::vector<int> inorder, int startIn, int endIn, 
                   std::vector<int> preorder, int startPre, int endPre)
{
    if(startIn == endIn)
        return new Tree<int>(inorder[startIn]);
    if(endIn < startIn)
        return NULL;
    
    int root = preorder[startPre];
    int rootIndex = find(inorder, startIn, endIn, root);
    int sizeLeft = rootIndex - startIn;
    
    Tree<int>* l = helper(inorder, startIn, rootIndex - 1,
                             preorder, startPre + 1, startPre + sizeLeft);
    
    Tree<int>* r = helper(inorder, rootIndex + 1, endIn,
                              preorder, startPre + 1 + sizeLeft, endPre);
    
    Tree<int>* res = new Tree<int>(root);
    res->left = l;
    res->right = r;
    return res;
}

int find(vector<int>& v, int start, int end, int root)
{
    return map[root];
}