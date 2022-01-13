// Minimum Size Subarray Sum: https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution 
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int right = 0, left = 0;
        int sum = 0, ans = INT_MAX;

        while(right < nums.size())
        {
            sum += nums[right];
            right++;

            while(sum >= target)
            {
                ans = min(ans, right - left);       // here right - left is the length of the current subarray;
                sum -= nums[left];
                left++;
            }
        }

        // If there is no such subarray then return 0
        return ans == INT_MAX ? 0 : ans;
    }
};