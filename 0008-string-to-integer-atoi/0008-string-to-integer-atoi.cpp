class Solution {
public:
    int myAtoi(string s) {
        long long res=0;
        int sign=1;
        int n=s.length();
        int i=0;
        while(i<n && s[i]==' '){
            i++;
        }
        if(i<n && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-'){
                sign=-1;
            }
            i++;
        }
        while(i<n && s[i]>='0' && s[i]<='9'){
            res=res*10+(s[i]-'0');
            if(sign*res<INT_MIN){
                return INT_MIN;
            }
            if(sign*res>INT_MAX){
                return INT_MAX;
            }
            i++;
        }
        return sign*res;
    }
};
