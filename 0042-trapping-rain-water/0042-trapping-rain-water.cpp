class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>prefix(n);
        vector<int>sufix(n);
        prefix[0]=height[0];
        for(int i=1;i<n;i++){
            prefix[i]=max(prefix[i-1],height[i]);
        }
        sufix[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--){
            sufix[i]=max(sufix[i+1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int leftmax=prefix[i];
            int rightmax=sufix[i];
            if(height[i]<leftmax && height[i]<rightmax){
                ans +=min(leftmax,rightmax)-height[i];
            }
        }
        return ans;
    }
};