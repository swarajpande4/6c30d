// Express as sum of power of natural numbers: https://practice.geeksforgeeks.org/problems/express-as-sum-of-power-of-natural-numbers5647/1

class Solution
{
public:
    long long numOfWays(int n, int x)
    {
        // Here, dp[i] represents the number of ways to represent i
        long long dp[n + 1] = {0};

        // 0 has one way to represent as sum of powers of natural numbers.
        // Base case
        dp[0] = 1;

        for(long long i = 1; i <= n; i++)
        {
            for(long long j = n; j >= i; j--)
            {
                long long y = pow(i, x);
                
                if(j >= y)
                    dp[j] += dp[j - y];
            }
        }

        return dp[n];
    }
};