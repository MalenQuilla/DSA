#include<iostream>
#include<math.h>
using namespace std;

int primecheck(int n)
{
    if(n < 2)
    {
        return 0;
    }
    for(int i = 2; i < n; ++i)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int divisors(int n)
{
    int a;
    a = round(sqrt(n));
    while (n % a != 0) 
        a -= 1;
    return a;
}

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};
TreeNode* initTreeNode(int val)
{
    TreeNode *Node = (TreeNode*) malloc(sizeof *Node);
    Node -> val = val;
    Node -> left = NULL;
    Node -> right = NULL;
    return Node;
}
TreeNode* factorizationTree(TreeNode *root, int n)
{
    int d1, d2;
    d1 = divisors(n);
    d2 = n / d1;
    root = initTreeNode(n);
    if(primecheck(root -> val) != 1)
    {
        root -> left = factorizationTree(root -> left, d1);
        root -> right = factorizationTree(root -> right, d2);
    }
    return root;
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
void displayFactorization(TreeNode *node)
{
    if (node != NULL)
    {
        if((node -> left == NULL) && (node -> right == NULL))
            cout << node -> val << " * ";
        displayFactorization(node -> left);
        displayFactorization(node -> right);
    }
}

int main()
{
    int n;
    TreeNode *root = NULL;
    cout << "Input number N: ";
    cin >> n;   
    root = factorizationTree(root, n);
    cout << "Binary Tree (NLR): " << endl;
    displayNLR(root);
    cout << endl << "Factorization: " << endl;
    displayFactorization(root);
    return 0;
}