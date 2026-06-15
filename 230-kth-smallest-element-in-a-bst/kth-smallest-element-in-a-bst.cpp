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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int ans;
        helper(root, ans, k, cnt);
        return ans;
    }

    void helper(TreeNode* root, int &ans, int k, int &cnt){
        if(root == NULL)
            return;
        helper(root->left, ans, k, cnt);
        cnt++;
        if(cnt == k){
            ans = root->val;
            return;
        }
        helper(root->right, ans, k, cnt);
    }
};