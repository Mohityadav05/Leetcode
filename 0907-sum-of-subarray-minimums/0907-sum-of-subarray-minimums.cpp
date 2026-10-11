class Solution {
private:
    void nextse(vector<int>& arr,vector<int>& nse,stack<int>& st){
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=arr.size();
            }else{
                nse[i]=st.top();
            }
            st.push(i);
        }
    }
    void previousse(vector<int>& arr,vector<int>& pse,stack<int>& st){
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[i]<arr[st.top()]){
                st.pop();
            }
            if(st.empty()){
                pse[i]=-1;
            }else{
                pse[i]=st.top();
            }
            st.push(i);
        }
    }
public:
    int sumSubarrayMins(vector<int>& arr) {
        vector<int>nse(arr.size());
        vector<int>pse(arr.size());
        stack<int>st;
        nextse(arr,nse,st);
        while(!st.empty()){
            st.pop();
        }
        previousse(arr,pse,st);
        long long total=0;
        int mod=1e9+7;
        for(int i=0;i<arr.size();i++){
            long long left=i-pse[i];
            long long right=nse[i]-i;
            total =(total+(left*right%mod)*arr[i]%mod)%mod;
        }
        return total;
    }
};