// IPL 2021: https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/

class Solution
{
public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k)
    {
        vector<int> res;
        deque<int> q;

        int i = 0;

        // Iterating over first k elements (1st window)
        for(i = 0; i < k; i++)
        {
            // For each element, the previously smaller elements 
            // are of no use, so we simply remove them from deque
            while(!q.empty() && arr[i] >= arr[q.back()])
                q.pop_back();
            
            // Adding new element at the back of the deque
            q.push_back(i);
        }

        // Iterating over the rest of the elements
        for(; i < n; i++)
        {
            // The element at the front of deque is the largest
            // of the previous window, adding it to result.
            res.push_back(arr[q.front()]);

            // Removing elements which are out of this window
            while(!q.empty() && q.front() <= i - k)
                q.pop_front();
            
            // Removing all the elements which are smaller than 
            // the element added currently.
            while(!q.empty() && (arr[i] >= arr[q.back()])) 
                q.pop_back();

            // Adding new element at the back of the deque
            q.push_back(i);
        }

        // Finally the element at the front of the deque is the largest
        // element of last window, so we simply add it to the list.
        res.push_back(arr[q.front()]);
        q.pop_front();

        return res;
    }
};