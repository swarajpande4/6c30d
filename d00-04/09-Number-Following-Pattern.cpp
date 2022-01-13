// Number Following Pattern: https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1

class Solution
{
public:
    string printMinNumberForPattern(string S)
    {
        string ans;

        stack<int> st;

        for(int i = 0; i <= S.length(); i++)
        {
            st.push(i + 1);

            // If all characters of S are processed, or current char is I
            if(i == S.length() || S[i] == 'I')
            {
                // Run till stack is empty
                while(!st.empty())
                {
                    ans += to_string(st.top());

                    st.pop();
                }
            }
        }

        return ans;
    }
};