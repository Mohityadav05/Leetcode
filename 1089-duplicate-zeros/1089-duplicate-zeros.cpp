class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i=0;
        while(i<arr.size()){
            if(arr[i]!=0){
                i++;
            }else{
                for(int j=arr.size()-1;j>i;j--){
                    arr[j]=arr[j-1];
                }
                if(i+1<arr.size()){
                    arr[i]=0;
                }
                i +=2;
            }
        }
    }
};