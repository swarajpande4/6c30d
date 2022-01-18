// Generate parenthesis: https://practice.geeksforgeeks.org/problems/generate-all-possible-parentheses/1/#

class Solution
{
public:
    void GenerateParenthesis(int n, int open, int close, string s, vector<string> &ans)
    {
        if (open == n && close == n)
        {
            ans.push_back(s);
            return;
        }

        if (open < n)
        {
            GenerateParenthesis(n, open + 1, close, s + "(", ans);
        }

        if (close < open)
        {
            GenerateParenthesis(n, open, close + 1, s + ")", ans);
        }
    }

    vector<string> AllParenthesis(int n)
    {
        vector<string> ans;
        GenerateParenthesis(n, 0, 0, "", ans);
        return ans;
    }
};