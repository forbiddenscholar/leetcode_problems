class Solution {
private:
    void helper(vector<vector<int>>& ans, vector<int>& curr, vector<int>& arr, int idx){
        if(idx == arr.size()){
            ans.push_back(curr);
            return;
        }
        curr.push_back(arr[idx]);
        helper(ans, curr, arr, idx+1);
        curr.pop_back();
        int next = idx+1;
        while((next < arr.size()) && arr[idx] == arr[next])
            next++;
        helper(ans, curr, arr, next);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(nums.begin(), nums.end());
        helper(ans, curr, nums, 0);
        return ans;
    }
};