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
    void preorderRecursive(TreeNode* root, vector<int> &arr){
        if (root == NULL)
            return;

        arr.push_back(root->val);
        preorderRecursive(root->left, arr);
        preorderRecursive(root->right, arr);
    }
    void preorderIterative(TreeNode* root, vector<int> &arr){

        if(root == NULL)
            return;
        stack<TreeNode*> st;
        st.push(root);

        while(!st.empty()){
            root = st.top();
            st.pop();
            arr.push_back(root->val);
            if(root->right != NULL)
                st.push(root->right);
            if(root->left != NULL)
                st.push(root->left);
        }
        return;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> arr;
        preorderIterative(root, arr);
        return arr;
    }
};