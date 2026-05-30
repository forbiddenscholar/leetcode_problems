class Solution {
private:

    long long mod = 1000000007;
    long long pow(long long num, long long exp){
        if(exp == 0)
            return 1;
        
        long long half = pow(num, exp/2);
        if(exp%2 == 0)
            return (half*half) % mod;
        return (((num % mod) * half) % mod * half) % mod;
    }
public:
    int countGoodNumbers(long long n) {
        // if n odd : pow(5, n/2 + 1) * pow(4, n/2)
        // if n even: pow(5, n/2) * pow(4, n/2)
        long long ans;
        if(n%2 == 0)
            ans = pow(5, n/2) * pow(4, n/2);
        else
            ans = pow(5, n/2 + 1) * pow(4, n/2);

        return ans % mod;
    }
};