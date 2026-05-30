class Solution {
private:
    double power(double num, int exp){
        if(exp == 0)
            return 1;
        
        double half = power(num, exp/2);
        if(exp % 2 == 0)
            return half*half;
        return num*half*half;
    }
public:
    double myPow(double x, int n) {
        // if n is negative then take reciprocal of x
        long long N = n;
        if(N < 0){
            x = 1/x;
            N = -1*N;
        }
        return power(x, n);
    }
};