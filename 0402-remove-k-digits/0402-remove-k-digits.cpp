
class Solution {
public:
    string removeKdigits(string num, int k) {
        string st="";

        for(int i=0;i<num.size();i++){
            while(!st.empty() && k>0 && st.back()>num[i]){
                st.pop_back();
                k=k-1;
            }
            st.push_back(num[i]);
        }

        while(k>0){
            st.pop_back();
            k--;
        }

        int i = 0;
        while(i < st.size() && st[i] == '0') {
            i++;
        }

        string res = st.substr(i);

        if(res.empty())
            return "0";

        return res;
    }
};
