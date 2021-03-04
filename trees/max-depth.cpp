#include <iostream>
class TreeNode
{
public:
    int val;
    TreeNode *left, *right;
};

int maxDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    int m = std::max(left, right);

    return m + 1;
}

int main()
{
    return 0;
}
