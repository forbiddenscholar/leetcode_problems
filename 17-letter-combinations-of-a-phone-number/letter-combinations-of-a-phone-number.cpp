class Solution {
private:
    void helper(int idx, string digits, string curr, vector<string>& ans, string combos[]){
        if(idx == digits.size()){
            ans.push_back(curr);
            return;
        }
        int digit = digits[idx] - '0';
        for(int i=0; i<combos[digit].size(); i++){
            helper(idx+1, digits, curr+combos[digit][i], ans, combos);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        string combos[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string curr = "";
        helper(0, digits, curr, ans, combos);
        return ans;
    }
};