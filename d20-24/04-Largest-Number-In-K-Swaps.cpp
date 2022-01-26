// Largest number in K swaps: https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1#

class Solution
{
    public:
    
    void findMaxUtil(string str, string &max, int k, int pos)
    {
        if(k == 0)
            return;
        
        // Pick the max value character from pos+1 onwards
        char maxm = str[pos];
        for(int i = pos + 1; i < str.length(); i++)
            if(maxm < str[i])
                maxm = str[i];
        
        // If the max value character is different, we decrement the value of k in order to limit number of swaps
        if(maxm != str[pos])
            k--;
        
        // We traverse the string from back till value of pos
        for(int i = str.length() - 1; i >= pos; i--)
        {
            // If the character is equal to max value character
            if(str[i] == maxm)
            {
                // We swap the value with current position
                swap(str[i], str[pos]);
                
                // We compare the resultant string with the max string, if greater we replace max by this resultant
                if(str.compare(max) > 0)
                    max = str;
                
                // We recursively call the function for the next position
                findMaxUtil(str, max, k, pos+1);
                
                // Lastly we backtrack
                swap(str[i], str[pos]);
            }
        }
    }
    
    string findMaximumNum(string str, int k)
    {
        string max = str;
        findMaxUtil(str, max, k, 0);
        return max;
    }
};