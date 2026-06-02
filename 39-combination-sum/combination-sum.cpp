class Solution {
private:
    void helper(vector<int>& arr, int target, int idx, vector<vector<int>> &result, vector<int> &curr){
        if(idx == arr.size()){
            if(target == 0){
                result.push_back(curr);
            }
            return;
        }
        if(arr[idx] <= target){
            curr.push_back(arr[idx]);
            helper(arr, target-arr[idx], idx, result, curr);
            curr.pop_back();
        }
        helper(arr, target, idx+1, result, curr);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // pick and not pick
        vector<vector<int>> result;
        vector<int> curr;
        helper(candidates, target, 0, result, curr);
        return result;
    }
};