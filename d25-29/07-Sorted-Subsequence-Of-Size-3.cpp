// Sorted subsequence of size 3: https://practice.geeksforgeeks.org/problems/sorted-subsequence-of-size-3/1/

class Solution
{
public:
    vector<int> find3Numbers(vector<int> arr, int N)
    {
        stack<int> s;

        for(int i = N - 1; i >= 0; i--)
        {
            // Popping the elements that are smaller than the current number
            while(!s.empty() && s.top() <= arr[i])
                s.pop();
            
            // Pushing every element since it will always be smaller than the top of the stack
            s.push(arr[i]);

            // If size of stack is now 3, we have found the answer
            if(s.size() == 3)
                break;
        }

        vector<int> ans;
        
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }

        // If size of answer is not 3, we don't get three numbers
        if(ans.size() != 3)
            return {};
        
        return ans;
    }
};