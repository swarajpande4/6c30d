// GCD of Strings: https://leetcode.com/problems/greatest-common-divisor-of-strings/

/*
The length of str1 should be greater than that of str2.
If str1 doesn't start with str2, then GCD is a empty string.
If str1 begins with str2, we cut off the prefix of str1 which is equal to str2, 
and recurse until one string is empty. 
In the above case, we return the string left in str1.
*/
class Solution 
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        if(str1.length() < str2.length())
            return gcdOfStrings(str2, str1);

        // If str1 doesn't have str2 as prefix
        else if(str1.find(str2) != 0)
            return "";
        
        // If str2 becomes empty, then the string left in str1 is the gcd
        else if(str2 == "")
            return str1;
        
        // We cut the common prefix of str1, which is equal to str2 and recurse
        else 
            return gcdOfStrings(str1.substr(str2.length()), str2);
    }
};