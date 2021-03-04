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

TreeNode *insert(TreeNode *root, int data)
{
    TreeNode *newNode = new TreeNode();
    newNode->val = data;
    newNode->left = NULL;
    newNode->right = NULL;

    if (root == NULL)
    {
        return newNode;
    }
    else
    {
        TreeNode *current = root;
        TreeNode *parent = NULL;

        while (true)
        {
            if (current->left == NULL)
            {
                current->left = newNode;
                return root;
            }
            else if (current->right == NULL)
            {
                current->right = newNode;
                return root;
            }
            else
            {
                current = current->right;
            }
        }
    }
}

bool isSymmetric(TreeNode *root)
{
    return isMirror(root, root);
}

bool isMirror(TreeNode *r1, TreeNode *r2)
{
    if (r1 == NULL && r2 == NULL)
        return true;
    if (r1 == NULL || r2 == NULL)
        return false;
    return (r1->val == r2->val) && isMirror(r1->right, r2->left) && isMirror(r1->left, r2->right);
}

int main()
{
    TreeNode *root = insert(NULL, 1);
    root = insert(root, 2);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 3);

    print2D(root);
    return 0;
}
