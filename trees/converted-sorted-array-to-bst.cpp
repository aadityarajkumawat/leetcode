#include <iostream>
#include <vector>
#include <queue>
#include "array-to-tree.h"
using namespace std;
#define COUNT 10

TreeNode* getRootOfConvertedBST(vector<int>& nums, int start, int end);

TreeNode* sortedArrayToBST(vector<int>& nums) {
    if(nums.size() == 0) {
	return NULL;
    }

    return getRootOfConvertedBST(nums, 0, nums.size() - 1);
}

TreeNode* getRootOfConvertedBST(vector<int>& nums, int start, int end) {
    if(start > end) {
	return NULL;
    }

    int mid = (start + end)/2;
    TreeNode* newRoot = new TreeNode();
    newRoot->val = nums[mid];

    newRoot->left = getRootOfConvertedBST(nums, start, mid-1);
    newRoot->right = getRootOfConvertedBST(nums, mid + 1, end);

    return newRoot;
}

int main()
{
    vector<int> nums = { 3, 5, 8, 1, -1, 8 };
    TreeNode* root = convertArrayToTree(nums);
    print2D(root);
    
    return 0;
}

