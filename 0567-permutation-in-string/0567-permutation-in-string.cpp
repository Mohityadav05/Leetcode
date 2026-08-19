class Solution {
public:
    bool isfreqSame(int freq[],int windfreq[]){
        for(int i=0;i<26;i++){
            if(freq[i]!=windfreq[i]){
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26]={0};
        for(int i=0;i<s1.length();i++){
            freq[s1[i]-'a']++;
        }
        int winSize=s1.length();
        for(int i=0;i<s2.length();i++){
            int idx=i;
            int winIdx=0;
            int windfreq[26]={0};
            while(winIdx<winSize && idx<s2.length()){
                windfreq[s2[idx]-'a']++;
                winIdx++;
                idx++;
            }
            if(isfreqSame(freq,windfreq)){
                return true;
            }
        }
        return false;
    }
};