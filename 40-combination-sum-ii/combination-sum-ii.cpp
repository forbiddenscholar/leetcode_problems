class Solution {
private:
    void helper(vector<int> &arr, vector<vector<int>>& ans, vector<int>& curr, int idx, int target){
        if(idx == arr.size()){
            if(target == 0)
                ans.push_back(curr);
            return;
        }
        if(arr[idx] <= target){
            curr.push_back(arr[idx]);
            helper(arr, ans, curr, idx+1, target-arr[idx]);
            curr.pop_back();
        }
        int next = idx+1;
        while(next<arr.size() && arr[next]==arr[idx])
            next++;
        helper(arr, ans, curr, next, target);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        helper(candidates, ans, curr, 0, target);
        return ans;
    }
};