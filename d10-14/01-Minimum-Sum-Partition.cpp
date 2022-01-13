// Minimum sum partition: https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1/

class Solution
{
public:
public:
    vector<int> isSubsetPossible(int arr[], int n, int sum)
    {
        bool t[n + 1][sum + 1];

        // Initialization
        for (int i = 0; i < sum + 1; i++)
            t[0][i] = false;
        for (int i = 0; i < n + 1; i++)
            t[i][0] = true;

        // DP
        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 1; j < sum + 1; j++)
            {
                if (arr[i - 1] <= j)
                    t[i][j] = t[i - 1][j - arr[i - 1]] || t[i - 1][j];
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        // Storing last row in vector
        vector<int> v;
        for (int j = 0; j < (sum / 2) + 1; j++)
            if (t[n][j])
                v.push_back(j);

        return v;
    }

    int minDifference(int arr[], int n)
    {
        // Your code goes here
        int range = accumulate(arr, arr + n, 0);

        vector<int> v = isSubsetPossible(arr, n, range);

        int mn = INT_MAX;
        for (int i = 0; i < v.size(); i++)
            mn = min(mn, range - 2 * v[i]);

        return mn;
    }
}