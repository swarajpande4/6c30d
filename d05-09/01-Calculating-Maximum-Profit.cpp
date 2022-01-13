// Maximum Profit: https://practice.geeksforgeeks.org/problems/maximum-profit4657/1

// Dynamic Programming approach (explanation)
// In this question, we are allowed to make, at max only k transactions.
// Let dp[t][i] represent, maximum profit using at most t transactions up till ith day.

// Then we can either,
// a)   Not do any transaction on the ith day, i.e. dp[t][i - 1]
// b)   We calcuate the maximum profit gained by selling on the ith day. 
//      We need to purchase it on any one of [0 ... i - 1] day. 
//      If we buy shares on jth day, and sell it on ith day, the max profit will be
//      price[i] - price[j] + dp[t - 1][j] where j varies from [0 .. i - 1].
//
// Hence, dp[t][i] = max(dp[t][i - 1], price[i] - price[j] + dp[t - 1][j])
// for all j in range [0 ... i - 1]
// 
// Time Complexity: O(K*N^2)

class Solution
{
public:
    int maxProfit(int K, int N, int A[])
    {
        int dp[K + 1][N + 1];
        
        for(int i = 0; i<= K; i++)
            dp[i][0] = 0;
        
        for(int i = 0; i <= N; i++)
            dp[0][i] = 0;

        for(int t = 1; t <= K; t++)
        {
            for(int i = 1; i < N; i++)
            {
                int currMax = INT_MIN;
                for(int j = 0; j < i; j++)
                    currMax = max(currMax, A[i] - A[j] + dp[t - 1][j]);
                
                dp[t][i] = max(dp[t][i - 1], currMax);
            }
        }

        return dp[K][N - 1];
    }
};