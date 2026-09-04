class Solution {
public:
    bool check(vector<vector<int>>& grid,int n,int row,int col,int expval){
        if(row<0 || col<0||row>=n||col>=n||grid[row][col]!=expval){
            return false;
        }
        if(expval==n*n-1){
            return true;
        }
        int ans1 = check(grid,n,row-2,col+1,expval+1);
        int ans2 = check(grid,n,row-1,col+2,expval+1);
        int ans3 = check(grid,n,row+1,col+2,expval+1);
        int ans4 = check(grid,n,row+2,col+1,expval+1);
        int ans5 = check(grid,n,row+2,col-1,expval+1);
        int ans6 = check(grid,n,row+1,col-2,expval+1);
        int ans7 = check(grid,n,row-1,col-2,expval+1);
        int ans8 = check(grid,n,row-2,col-1,expval+1);
        return ans1||ans2||ans3||ans4||ans5||ans6||ans7||ans8;
    }
    bool checkValidGrid(vector<vector<int>>& grid) {
        return check(grid,grid.size(),0,0,0);
    }
};