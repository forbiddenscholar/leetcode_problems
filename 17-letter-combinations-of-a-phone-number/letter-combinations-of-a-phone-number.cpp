class Solution {
public:
    vector<string> ans;
    string curr;
    vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void backtrack(int idx, string& digits){
        if(idx == digits.size()){
            ans.push_back(curr);
            return;
        }
        int digit = digits[idx]-'0';
        string letters = mp[digit];
        for(char c : letters){
            curr.push_back(c);
            backtrack(idx+1, digits);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        backtrack(0, digits);
        return ans;
    }
};