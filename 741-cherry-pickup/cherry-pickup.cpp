class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    int solve(vector<vector<int>>& grid,int r1,int c1,int r2){
        int n=grid.size();
        int c2=r1+c1-r2;
        //outside grid
        if(r1>=n || r2>=n || c1>=n || c2>=n){
            return -1e9;
        }
        //blocked cells
        if(grid[r1][c1]==-1 ||grid[r2][c2]==-1){
            return -1e9;
        }
        //reached destination
        if(r1==n-1 && c1==n-1){
            return grid[r1][c1];
        }
        //already calculated
        if(dp[r1][c1][r2]!=-1){
            return dp[r1][c1][r2];
        }
        int cherries=0;
        //if both are in same cell
        if(r1==r2 & c1==c2){
            cherries=grid[r1][c1];
        }
        //different cells
        else{
            cherries = grid[r1][c1] + grid[r2][c2];
        }
        int best = max({
            solve(grid,r1+1,c1,r2+1),
            solve(grid,r1+1,c1,r2),
            solve(grid,r1,c1+1,r2+1),
            solve(grid,r1,c1+1,r2)
        });
        return dp[r1][c1][r2]=cherries+best;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n=grid.size();
        dp = vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n, -1)));
        int ans=solve(grid,0,0,0);
        return max(0,ans);
    }
};