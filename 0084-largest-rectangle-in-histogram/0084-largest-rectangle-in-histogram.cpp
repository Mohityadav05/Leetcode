class Solution {
private:
    void previousse(vector<int>& heights,vector<int>& pse,stack<int>& st){
        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
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
    void nextse(vector<int>& heights,vector<int>& nse,stack<int>& st){
        for(int i=heights.size()-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i]=heights.size();
            }else{
                nse[i]=st.top();
            }
            st.push(i);
        }
    }
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int>pse(heights.size());
        vector<int>nse(heights.size());
        stack<int>st;
        previousse(heights,pse,st);
        while(!st.empty()){
            st.pop();
        }
        nextse(heights,nse,st);
        int maxi=0;
        for(int i=0;i<heights.size();i++){
            maxi=max(maxi,heights[i]*(nse[i]-pse[i]-1));
        }
        return maxi;
    }
};