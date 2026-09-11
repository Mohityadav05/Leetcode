class Solution {
public:
    vector<string> ans;

    unordered_map<char, vector<char>> mp = {
        {'2', {'a', 'b', 'c'}},
        {'3', {'d', 'e', 'f'}},
        {'4', {'g', 'h', 'i'}},
        {'5', {'j', 'k', 'l'}},
        {'6', {'m', 'n', 'o'}},
        {'7', {'p', 'q', 'r', 's'}},
        {'8', {'t', 'u', 'v'}},
        {'9', {'w', 'x', 'y', 'z'}}
    };

    void function(string& digits, int n, string& str) {

        if(n == digits.length()) {
            ans.push_back(str);
            return;
        }

        for(char ch : mp[digits[n]]) {

            str.push_back(ch);

            function(digits, n + 1, str);

            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if(digits.empty())
            return {};

        string str = "";

        function(digits, 0, str);

        return ans;
    }
};