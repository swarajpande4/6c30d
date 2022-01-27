// Split array largest sum: https://leetcode.com/problems/split-array-largest-sum/

class Solution 
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int max = 0;
        int sum = 0;
        int n = nums.size();

        sum = accumulate(nums.begin(), nums.end(), 0);
        max = *max_element(nums.begin(), nums.end());

        int low = max;
        int high = sum;
        int ans = -1;

        while(low <= high)
        {
            int mid = (low + high) / 2;
            
            if(isSafe(nums, mid, m))
            {
                ans = mid;
                high = mid - 1;
            }
            else 
                low = mid + 1;
        }

        return ans;
    }

    bool isSafe(vector<int> nums, int k, int m)
    {
        int count = 1;
        int sum = 0;

        for(int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            
            if(sum > k)
            {
                sum = nums[i];
                count++;
            }
        }

        if(count <= m)
            return true;
        
        return false;
    }
};