class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xo = 0;
        for(int val :nums){
            xo=xo^val;
        }
        return xo;
    }
};