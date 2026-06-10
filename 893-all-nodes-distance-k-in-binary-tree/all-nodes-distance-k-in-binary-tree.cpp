/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &parent_track){
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
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParent(root, parent_track);
        // bfs 
        queue<TreeNode*> q;
        unordered_map<TreeNode*, bool> visited;
        q.push(target);
        visited[target] = true;
        int curr_level = 0;
        while(!q.empty()){
            if(curr_level++ == k)
                break;
            int size = q.size();
            for(int i=0; i<size; i++){
                TreeNode* curr_node = q.front();
                q.pop();
                if(curr_node->left && !visited[curr_node->left]){
                    q.push(curr_node->left);
                    visited[curr_node->left] = true;
                }
                if(curr_node->right && !visited[curr_node->right]){
                    q.push(curr_node->right);
                    visited[curr_node->right] = true;
                }
                if(parent_track[curr_node] && !visited[parent_track[curr_node]]){
                    q.push(parent_track[curr_node]);
                    visited[parent_track[curr_node]] = true;
                }
            }
        }
        vector<int> result;
        while(!q.empty()){
            result.push_back(q.front()->val);
            q.pop();
        }
        return result;
    }
};