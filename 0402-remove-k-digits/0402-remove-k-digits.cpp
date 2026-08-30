class Solution {
public:
    string removeKdigits(string num, int k) {

        string st = "";

        for(int i = 0; i < num.size(); i++) {

            while(!st.empty() && k > 0 && st.back() > num[i]) {
                st.pop_back();
                k--;
            }

            st.push_back(num[i]);
        }

        // Remove remaining digits from the end
        while(k > 0) {
            st.pop_back();
            k--;
        }

        // Remove leading zeros
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