// Longest Mountain in Array: https://leetcode.com/problems/longest-mountain-in-array/

// Here, we count up and down length of a moutain.
// When arr[i - 1] == arr[i] i.e. mountain flattens out, or
//      downLength > 0 and arr[i - 1] < arr[i] i.e. the current mountain ends and we're at the start of another one
//      we reset upLength and downLength back to zero.
//
// If downLength and upLength are not zero, calculate the length of the current mountain using 
// downLength + upLength + 1, and store the result if it greater than the already stored one.

class Solution
{
public:
    int longestMountain(vector<int>& arr)
    {
        int ans = 0, upLength = 0, downLength = 0;

        for(int i = 1; i < arr.size(); i++)
        {
            if(arr[i - 1] == arr[i] || downLength && arr[i - 1] < arr[i])
                upLength = downLength = 0;
            
            upLength += arr[i - 1] < arr[i];
            downLength += arr[i - 1] > arr[i];

            if(upLength && downLength)
                ans = max(ans, upLength + downLength + 1)
        }

        return ans;
    }
}