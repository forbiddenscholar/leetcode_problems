/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = INT_MIN;
        helper(root, max_sum);
        return max_sum;
    }

    int helper(TreeNode* node, int& max_sum) {
        if(node == NULL)
            return 0;
        int l_sum = max(0, helper(node->left, max_sum));
        int r_sum = max(0, helper(node->right, max_sum));
        int sum = l_sum + r_sum + node->val;
        if(sum > max_sum)
            max_sum = sum;
        return max(node->val+l_sum, node->val+r_sum);
    }
};