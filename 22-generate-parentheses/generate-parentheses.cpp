class Solution {
private:
    vector <string> res;
    void backtrack(string curr, int open, int close, int n){
        if(curr.length() == 2*n)
            res.push_back(curr);
        if(open<n)
            backtrack(curr + '(', open+1, close, n);
        if(close<open)
            backtrack(curr + ')', open, close+1, n);
    }
public:
    vector<string> generateParenthesis(int n) {
        backtrack("", 0, 0, n);
        return res;
    }
};