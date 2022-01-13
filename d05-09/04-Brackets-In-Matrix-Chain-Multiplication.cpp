// Brackets in MCM: https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/

class Solution
{
public:

    string result;
    void generateParenthesis(int i, int j, int b[27][27], char &curr)
    {
        if(i == j)
        {
            result += curr;
            curr++;
            return;
        }
        
        result += '(';

        // Recursive call for putting brackets around subexpr i to b[i][j]
        generateParenthesis(i, b[i][j], b, curr);

        // Recursive call for putting brackets around subexpr b[i][j] + 1 to j
        generateParenthesis(b[i][j] + 1, j, b, curr);

        result += ')';
    }

    string matrixChainOrder(int p[], int n)
    {
        int m[n][n];        // dp matrix
        int b[27][27];        // matrix to store optimal break point in subexpr from i to j

        for(int i = 1; i < n; i++)
            m[i][i] = 0;
        
        // L is chain length
        for(int L = 2; L < n; L++)
        {
            for(int i = 1; i < n - L + 1; i++)
            {
                int j = i + L - 1;
                m[i][j] = INT_MAX;

                for(int k = i; k < j; k++)
                {
                    int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                    if(q < m[i][j])
                    {
                        m[i][j] = q;
                        b[i][j] = k;        // Put the bracket's point
                    }
                }
            }
        }

        char curr = 'A';
        generateParenthesis(1, n - 1, b, curr);

        return result;
    }
};