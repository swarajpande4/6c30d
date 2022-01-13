// First non-repeating character in a stream: https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1/

class Solution
{
public:
    string FirstNonRepeating(string A)
    {
        queue<char> q;
        int count[26] = {0};

        string ans = "";

        // Traversing the whole stream
        for(int i = 0; i < A.length(); i++)
        {
            q.push(A[i]);
            count[A[i] - 'a']++;

            // Check for non repeating character
            while(!q.empty())
            {
                if(count[q.front() - 'a'] > 1)
                    q.pop();
                else 
                {
                    ans += q.front();
                    break;
                }
            }

            // If there is no such character
            if(q.empty())
                ans += '#';
        }

        return ans;
    }
};