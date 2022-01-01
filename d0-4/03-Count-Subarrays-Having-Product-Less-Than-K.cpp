// Count subarrays having product less than k: https://practice.geeksforgeeks.org/problems/count-the-subarrays-having-product-less-than-k1708/1/#

class Solution
{
public:
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {
        if (k <= 1)
            return 0;

        long long prod = 1;
        int result = 0;

        int left = 0;
        int right = 0;

        while (right < n)
        {
            prod *= a[right];

            while (prod >= k)
            {
                prod /= a[left];
                left++;
            }

            result += right - left + 1;
            right++;
        }

        return result;
    }
};