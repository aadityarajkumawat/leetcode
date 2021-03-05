#include "array-to-tree.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define COUNT 10

TreeNode::TreeNode() {};

TreeNode::TreeNode(int val, TreeNode* left, TreeNode* right) {
    this->val = val;
    this->left = left;
    this->right = right;
}

TreeNode* insertByLevel(TreeNode* root, int data) {
    if(root == NULL) {
	return new TreeNode(data, NULL, NULL);
    }

    queue<TreeNode*> queueOfTreeNodes;
    queueOfTreeNodes.push(root);

    while(!queueOfTreeNodes.empty()) {
	TreeNode* temp = queueOfTreeNodes.front();
	queueOfTreeNodes.pop();
	
	if(temp->left == NULL) {
	    temp->left = new TreeNode(data, NULL, NULL);
	    return root;
	} else {
	    queueOfTreeNodes.push(temp->left);
	}

	if(temp->right == NULL) {
	    temp->right = new TreeNode(data, NULL, NULL);
	    return root;
	} else {
	    queueOfTreeNodes.push(temp->right);
	}
    }
    return root;
}

TreeNode* convertArrayToTree(vector<int>& nums) {
    TreeNode* root = NULL;

    for(int i = 0;i < nums.size(); i++) {
	root = insertByLevel(root, nums[i]);
    }

    return root;
}


void print2DUtil(TreeNode *root, int space)
{
    if (root == NULL)
        return;

    space += COUNT;

    print2DUtil(root->right, space);

    cout << endl;
    for (int i = COUNT; i < space; i++) {
        cout << " ";
    }
    cout << root->val << "\n";

    print2DUtil(root->left, space);
}

void print2D(TreeNode *root)
{
    print2DUtil(root, 0);
}
