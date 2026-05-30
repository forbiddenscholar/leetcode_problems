class Solution {
private:
    vector <string> res;
    void backtrack(string curr, int n){
        if(curr.length() == n){
            res.push_back(curr);
            return;
        }
        if(curr[(curr.length() - 1)] == '0')
            backtrack(curr + '1', n);
        if(curr[(curr.length() - 1)] == '1'){
            backtrack(curr + '0', n);
            backtrack(curr + '1', n);
        }
    }
public:
    vector<string> validStrings(int n) {
        backtrack("0", n);
        backtrack("1", n);
        return res;
    }
};