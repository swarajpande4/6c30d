// Find Missing and Repeating: https://www.interviewbit.com/problems/repeat-and-missing-number-array/

class Solution 
{
public:
    vector<int> repeatedNumber(const vector<int> &arr)
    {
        int x = 0;      // Missing number
        int y = 0;      // Repeating number

        int xor1 = 0;
        int n = arr.size();

        // (all elements) ^ (all number from 1 to n) = Will produce two numbers
        
        // Taking xor of all the array elements
        for(int i = 0; i < n; i++)
            xor1 ^= arr[i];
        
        // Xor the previous result with all the numbers 1 to n
        for(int i = 1; i <= n; i++)
            xor1 ^= i;
        
        // We have x ^ y, now we will find the rightmost set bit, 
        // into buckets accordingly and divide the numbers
        int setBitNumber = xor1 & ~(xor1 - 1);

        for(int i = 0; i < n; i++)
        {
            if(arr[i] & setBitNumber)
                // arr[i] belongs to first set
                x = x ^ arr[i];
            
            else 
                // arr[i] belongs to second set
                y = y ^ arr[i];
        }    

        // Again traversing through all the numbers from 1 to n,
        // and classifying them into 2 buckets, according to their rightmost set bit
        for(int i = 1; i <= n; i++)
        {
            if (i & setBitNumber)
                // i belongs to first set
                x = x ^ i;

            else
                // i belongs to second set
                y = y ^ i;
        }

        int xCount = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == x)
                xCount++;
        }

        if (xCount == 0)
            return {y, x};

        return {x, y};
    }
};