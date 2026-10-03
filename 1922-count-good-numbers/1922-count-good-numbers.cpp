class Solution {
public:
    long long power(long long x, long long n){
        long long ans = 1;
        long long mod = 1000000007;

        while(n > 0){
            if(n % 2 == 0){
                x = (x * x) % mod;
                n = n / 2;
            }
            else{
                ans = (ans * x) % mod;
                n = n - 1;
            }
        }

        return ans;
    }

    int countGoodNumbers(long long n) {
        long long mod = 1000000007;

        long long even;
        long long prime;

        if(n % 2 == 0){
            even = power(5, n / 2);
            prime = power(4, n / 2);
        }
        else{
            even = (power(5, n / 2) * 5) % mod;
            prime = power(4, n / 2);
        }

        long long ans1 = (even * prime) % mod;

        return ans1;
    }
};