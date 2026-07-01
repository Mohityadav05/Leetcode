class Solution {
public:
    bool isPalindrome(int x) {
        long sum=0;
        int y=x;
        while(x>0){
            int temp = x % 10;
            x/=10;
            sum=sum*10+temp;
        }
        if(sum==y){
            return true;
        }
        else{
            return false;
        }
    }
};