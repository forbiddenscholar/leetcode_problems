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
    void makeParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node->left){
                q.push(node->left);
                parent_track[node->left] = node;
            }
            if(node->right){
                q.push(node->right);
                parent_track[node->right] = node;
            }
        }
    }
    TreeNode* findStartNode(TreeNode* root, int start){
        if(!root)
            return NULL;
        if(root->val == start)
            return root;
        TreeNode* leftResult = findStartNode(root->left, start);
        if(leftResult != NULL)
            return leftResult;
        return findStartNode(root->right, start);
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        // here i'll require at first a dfs where i'll store all the parental links
        // nextly, i'll do bfs, where i'll find all the adjacent nodes and add  the time
        unordered_map <TreeNode*, TreeNode*> parent_track; // <node, itsParent>
        makeParent(root, parent_track);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        TreeNode* target = findStartNode(root, start);

        q.push(target);
        visited[target] = true;
        int time = 0;
        while(!q.empty()){
            int size = q.size();
            bool burned = false;
            for(int i=0; i<size; i++){
                TreeNode* curr_node = q.front();
                q.pop();
                if(curr_node->left && !visited[curr_node->left]){
                    q.push(curr_node->left);
                    visited[curr_node->left] = true;
                    burned = true;
                }
                if(curr_node->right && !visited[curr_node->right]){
                    q.push(curr_node->right);
                    visited[curr_node->right] = true;
                    burned = true;
                }
                if(parent_track[curr_node] && !visited[parent_track[curr_node]]){
                    q.push(parent_track[curr_node]);
                    visited[parent_track[curr_node]] = true;
                    burned = true;
                }
            }
            if(burned) time++;
        }
        return time;
    }
};