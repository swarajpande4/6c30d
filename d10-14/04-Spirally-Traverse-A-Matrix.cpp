// Spirally traversing a matrix: https://practice.geeksforgeeks.org/problems/spirally-traversing-a-matrix-1587115621/1/

class Solution
{
public:
    vector<int> spirallyTraverse(vector<vector<int>> a, int m, int n)
    {
        vector<int> res;
        int i, k, l;
        k = l = 0;

        while (k < m && l < n)
        {
            for (i = l; i < n; i++)
                res.push_back(a[k][i]);
            k++;

            for (i = k; i < m; i++)
                res.push_back(a[i][n - 1]);
            n--;

            if (k < m)
            {
                for (i = n - 1; i >= l; i--)
                    res.push_back(a[m - 1][i]);
                m--;
            }
            if (l < n)
            {
                for (i = m - 1; i >= k; i--)
                    res.push_back(a[i][l]);
                l++;
            }
        }
        return res;
    }
};