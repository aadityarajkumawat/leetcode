#include <iostream>
#define COUNT 10

class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

void print2DUtil(TreeNode *root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;

    print2DUtil(root->right, space);

    std::cout << std::endl;
    for (int i = COUNT; i < space; i++)
    {
        std::cout << " ";
    }
    std::cout << root->val << "\n";

    print2DUtil(root->left, space);
}

void print2D(TreeNode *root)
{
    print2DUtil(root, 0);
}

void inorder(TreeNode *root)
{
    if (root != NULL)
    {
        std::cout << root->val << " ";
        inorder(root->left);
        inorder(root->right);
    }
}

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if (p == NULL || q == NULL)
    {
        return false;
    }
    if (p->val != q->val)
    {
        return false;
    }

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
    TreeNode *p = new TreeNode();
    TreeNode *a = new TreeNode();
    TreeNode *b = new TreeNode();

    p->val = 1;
    a->val = 2;
    b->val = 3;

    a->left = NULL;
    a->right = NULL;
    b->left = NULL;
    b->right = NULL;

    p->left = a;
    p->right = b;

    print2D(p);

    TreeNode *q = new TreeNode();
    TreeNode *a1 = new TreeNode();
    TreeNode *b1 = new TreeNode();

    q->val = 1;
    a1->val = 2;
    b1->val = 3;

    a1->left = NULL;
    a1->right = NULL;
    b1->left = NULL;
    b1->right = NULL;

    q->left = a;
    q->right = b;

    print2D(q);

    if (isSameTree(p, q))
    {
        std::cout << "Same" << std::endl;
    }

    return 0;
}
