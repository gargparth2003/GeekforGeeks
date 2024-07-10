

class Solution{
public:
    int solve(vector<vector<int>> &mat,int n,int m,int &maxi) {
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int r = dp[i][j+1];
                int d = dp[i+1][j];
                int dig = dp[i+1][j+1];
                if(mat[i][j]==1) {
                    dp[i][j] = 1+min(r,min(d,dig));
                    maxi = max(maxi,dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
        
    }
    int maxSquare(int n, int m, vector<vector<int>> mat){
        int maxi=0;
        solve(mat,n,m,maxi);
        return maxi;
    }
};


// just the main code  
 // link --https://www.geeksforgeeks.org/problems/largest-square-formed-in-a-matrix0806/