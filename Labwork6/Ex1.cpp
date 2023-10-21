#include<iostream>
#include<math.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *parent;
    TreeNode *left;
    TreeNode *right;
};
TreeNode* initTreeNode(int val)
{
    TreeNode *Node = (TreeNode*) malloc(sizeof *Node);
    Node -> val = val;
    Node -> parent = NULL;
    Node -> left = NULL;
    Node -> right = NULL;
    return Node;
}
struct index
{
    int ind = 0;
};
TreeNode* CreateTree(int max, int head, int tail, TreeNode *oldroot, int i, int h, int a[], index *index)
{
    TreeNode *root = NULL;
    int mid = (head + tail)/2;
    if (head > tail)
        return NULL;
    if (i != h)
    {
       root = initTreeNode(max);
    }
    else
    {
        root = initTreeNode(a[index -> ind]);
        index -> ind += 1;
    }
    root -> parent = oldroot;
    root -> left = CreateTree(max, head, mid - 1, root, i + 1, h, a, index);
    root -> right = CreateTree(max, mid + 1, tail, root, i + 1, h, a, index);
    return root;
}
int BST(TreeNode *root, int h, int count)
{
    if(count == h)
    {
        if(root -> left -> val < root -> right -> val)
            root -> val = root -> left -> val;
        else
            root -> val = root -> right -> val;
        return 1;
    }
    BST(root -> left, h, count + 1);
    BST(root -> right, h, count + 1);
    return 0;
}
void displayNLR(TreeNode *node)
{
    if (node != NULL)
    {
        cout << node -> val << " ";
        displayNLR(node -> left);
        displayNLR(node -> right);
    }
}
struct check
{
    int notfound = -1;
};
void search(TreeNode *node, int x, check *chck)
{
    if (node != NULL)
    {
        if (node -> val == x)
        {
            chck -> notfound = 0;
            cout << "The subtree with the found node as the root: ";
            displayNLR(node);
            cout << endl;
            return;
        }
        search(node -> left, x, chck);
        search(node -> right, x, chck);
    }
}
int main()
{
    int n, h, leaf, x;
    TreeNode *root = NULL, *foundnode = NULL;
    index *ind, Ind;
    ind = &Ind;
    check *chck, Chck;
    chck = &Chck;
    cout << "Input the number of elements of the array data: ";
    cin >> n;
    if (log2(n) == (int)log2(n))
        h = log2(n) + 1;
    else h = log2(n) + 2;
    leaf = pow(2, h - 1);
    int a[leaf];
    for (int i = 0; i < n; ++i)
    {
        cout << "Input a[" << i + 1 << "] = ";
        cin >> a[i];
    }
    int max = a[0];
    for (int i = 1; i < n; ++i)
        if (max < a[i])
            max = a[i];
    max += 1;
    for (int i = n; i < leaf; ++i)
        a[i] = max;
    int numofnodes = 0;
    for (int i = 0; i < h; ++i)
        numofnodes += pow(2, i);
    root = CreateTree(max, 0, numofnodes - 1, NULL, 1, h, a, ind);
    for (int i = 1; i < h; ++i)
        BST(root, h - i, 1);
    cout << "Binary Tree: ";
    displayNLR(root);
    cout << endl << "Input value that needs to be found: ";
    cin >> x;
    search(root, x, chck);
    if (chck -> notfound == -1)
        cout << -1;
    return 0;
}