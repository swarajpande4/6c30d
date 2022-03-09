// Possible words from phone digits: https://practice.geeksforgeeks.org/problems/possible-words-from-phone-digits-1587115620/1/

class Solution 
{
    string getNumString(int n) 
    {
        switch(n) 
        {
            case 2: return "abc";
            case 3: return "def";
            case 4: return "ghi";
            case 5: return "jkl";
            case 6: return "mno";
            case 7: return "pqrs";
            case 8: return "tuv";
            case 9: return "wxyz";
        }
    }

    void getWords(int i, int n, int a[], string curr, vector<string> &res) 
    {
        if(i == n) 
        {
            res.push_back(curr);
            return;
        }
        
        string s = getNumString(a[i]);
        for(int j=0; j<s.size(); j++)
            getWords(i+1, n, a, curr+s[j], res);
    }

public:
    vector<string> possibleWords(int a[], int N) 
    {
        vector<string> res;
        getWords(0, N, a, "", res);
        return res;
    }
};

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Leetcode Question Solution
class Solution 
{
    string getNumericString(char n)
    {
        switch(n)
        {
            case '2': return "abc";
            case '3': return "def";
            case '4': return "ghi";
            case '5': return "jkl";
            case '6': return "mno";
            case '7': return "pqrs";
            case '8': return "tuv";
            case '9': return "wxyz";
        }
        
        return "";
    }
    
    
    void getWords(int i, int n, string a, string curr, vector<string> &res)
    {
        if(i == n)
        {
            res.push_back(curr);
            return;
        }
        
        string s = getNumericString(a[i]);
        
        for(int j = 0; j < s.size(); j++)
            getWords(i + 1, n, a, curr + s[j], res);
    }
    
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> res;
        
        if(digits.size() == 0)
            return res;
        
        getWords(0, digits.size(), digits, "", res);
        return res;
    }
};