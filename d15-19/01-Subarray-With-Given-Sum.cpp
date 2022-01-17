// Subarray with given sum: https://practice.geeksforgeeks.org/problems/subarray-with-given-sum-1587115621/1#

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, long long s)
    {
        int low = 0, high = n - 1;
        int sum = 0;
        
        int index = 0;
        
        while(low <= high)
        {
            sum += arr[index];
            if(sum == s)
                return {low + 1, index + 1};
            
            if(sum > s)
            {
                while(sum > s)
                {
                    sum -= arr[low];
                    low++;
                    if(sum == s)
                        return {low + 1, index + 1};
                }
            }
            
            index++;
        }
        
        return {-1};
    }
};