class Solution {
public:
long long mod=1e9+7;
long long power(long long base,long long expo){
    if(expo==0){
        return 1;
    }
    long long half=power(base,expo/2);
    long long ans=(half*half)%mod;
    if(expo%2==1){
        ans=(ans*base)%mod;
    }
    return ans;
}
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd= n/2;
        long long ans=(power(5,even)*power(4,odd))%mod;
        return ans;
    }
};