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
private:
    void inorder(TreeNode* root, vector<int> &arr){
        // base condition
        if(root == NULL)
            return ;
        // recursion
        inorder(root->left, arr);
        arr.push_back(root->val);
        inorder(root->right, arr);
    }
    void morrisInorder(TreeNode* root, vector<int> &arr){
        TreeNode* curr = root;
        while(curr != NULL){
            // case 1 left does not exist
            if(curr->left == NULL){
                arr.push_back(curr->val);
                curr = curr->right;
            }
            // case 2 if left exist
            else{
                // if the thread does not exist
                TreeNode* prev = curr->left;
                while(prev->right && prev->right != curr){
                    prev = prev->right;
                }
                if(prev->right == NULL){
                    prev->right = curr;
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    arr.push_back(curr->val);
                    curr = curr->right;
                }
            }
        }
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        // inorder(root, arr);
        morrisInorder(root, arr);
        return arr;
    }
};