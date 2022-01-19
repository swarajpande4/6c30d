// Number of distinct words with k maximum contiguous vowels

/*
    Intuition:
    If kvowelwords(i, j) describes the number of strings of length i
    where last j characters are vowels, then 
    kvowelwords(i, j) = kvowelwords(i - 1, j - 1) * 5
*/

class Solution
{
private:
    long long int power(long long int x, long long int y, long long int p)
    {
        long long int res = 1ll;

        x %= p;
        if(x == 0)
            return 0;
        
        while(y > 0)
        {
            if(y & 1)
                res = (res * x) % p;
            
            y = y >> 1;
            x = (x * x) % p;
        }

        return res;
    }

public:
    int kvowelwords(int N, int K)
    {
        long long int i, j;
        long long int mod = 1e9 + 7;

        long long int dp[N + 1][K + 1] = {0};
        long long int sum = 1;

        for(i = 1; i <= N; i++)
        {
            // dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + ... + dp[i - 1][k]) * 21
            dp[i][0] = sum * 21;
            dp[i][0] %= mod;

            sum = dp[i][0];

            for(j = 1; j <= K; j++)
            {
                // If j > i, there are no possible ways to create a string with length i and vowels j
                if(j > i)
                    dp[i][j] = 0;
                
                // If j = i, all the characters must be vowels
                else if(j == i)
                    dp[i][j] = power(5ll, i, mod);
                
                // Using the recurrence 
                else
                    dp[i][j] = dp[i - 1][j - 1] * 5;
                
                dp[i][j] %= mod;
                sum += dp[i][j];
                sum %= mod;
            }
        }

        return sum;
    }
};