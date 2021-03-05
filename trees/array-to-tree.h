#include <vector>

class TreeNode {
    public:
	int val;
	TreeNode* left;
	TreeNode* right;

	/** Initialize Node */
	TreeNode();
	TreeNode(int val, TreeNode* left, TreeNode* right);
};

TreeNode* convertArrayToTree(std::vector<int>& nums);
void print2DUtil(TreeNode* root, int space);
void print2D(TreeNode* root);
