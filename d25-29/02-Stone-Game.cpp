// Stone game: https://leetcode.com/problems/stone-game/

class Solution 
{
public:
    bool stoneGame(vector<int>& piles) 
    {
        return true; 
    }
    
    /*
    // 2D DP
    
    bool stoneGame(vector<int> &piles)
    {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for(int i = 0; i < n; i++)
            dp[i][i] = piles[i];
        
        for(int d = 1; d < n; d++)
            for(int i = 0; i < n - d; i++)
                dp[i][i + d] = max(p[i] - dp[i + 1][i + d], p[i + d] - dp[i][i + d - 1]);
        
        return dp[0][n - 1];
    }
    
    */
    
};