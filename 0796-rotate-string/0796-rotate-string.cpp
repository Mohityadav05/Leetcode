class Solution {
public:
    bool rotateString(string s, string goal) {
       for(int i=0;i<s.size();i++){
        if(s==goal){
            return true;
        }
        char last=s.back();
        s.pop_back();
        s=last+s;
       } 
       return false;
    }
};