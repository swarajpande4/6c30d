// Column name from a given column number: https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number4244/1/

class Solution 
{
public:
    string colName(long long int n)
    {
        string ans = "";

        while(n)
        {
            char c = 'A' + (n - 1) % 26;
            ans = c + ans;
            n = (n - 1) / 26;
        }

        return ans;
    }
};