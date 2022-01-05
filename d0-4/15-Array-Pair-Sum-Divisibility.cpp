// Array pair sum divisibility: https://practice.geeksforgeeks.org/problems/array-pair-sum-divisibility-problem3257/1

class Solution
{
public:
    bool canPair(vector<int> nums, int k)
    {
        map<int, int> m;
        int n = nums.size();

        // If length of array is odd, it cannot be divided up into pairs
        if(n & 1)
            return false;

        // Counting frequency of all remainders
        for(int i = 0; i < n; i++)
            m[((nums[i] % k) + k) % k]++;
        
        
        if(m[0] % 2)
            return false;

        for(int i = 1; i < k; i++)
            // If freqency of remainder is not equal to frequency of k - remainder,
            // then pairing is not possible.
            if(m[i] != m[k - i])
                return false;

        return true;
    }
};