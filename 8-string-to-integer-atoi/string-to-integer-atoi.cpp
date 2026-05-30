class Solution {
private:
    int helper(string s, int i, long long num, int sign){
        // return if string is finished or a non-digit found
        if(i > s.size() || !isdigit(s[i]))
            return sign*num;
        num = num*10 + (s[i] - '0');

        // overflow conditions
        if(sign*num > INT_MAX) return INT_MAX;
        if(sign*num < INT_MIN) return INT_MIN;

        // move to next index
        return helper(s, i+1, num, sign);
        
    }
public:
    int myAtoi(string s, int i=0) {
        // remove all the whitespaces
        while(i <= s.size() && s[i] == ' ') i++;

        // take the sign
        int sign = 1;
        if(i<s.size() && (s[i] == '-' || s[i] == '+')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        return helper(s, i, 0, sign);
    }
};