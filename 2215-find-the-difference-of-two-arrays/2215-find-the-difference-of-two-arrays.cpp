class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> st1, st2;

        for(int x : nums1){
            st1.insert(x);
        }

        for(int x : nums2){
            st2.insert(x);
        }

        vector<vector<int>> answer;

        vector<int> ans1, ans2;

        for(int x : st1){
            if(st2.find(x) == st2.end()){
                ans1.push_back(x);
            }
        }

        for(int x : st2){
            if(st1.find(x) == st1.end()){
                ans2.push_back(x);
            }
        }

        answer.push_back(ans1);
        answer.push_back(ans2);

        return answer;
    }
};