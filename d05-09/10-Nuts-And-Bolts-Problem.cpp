// Nuts and Bolts Problem: https://practice.geeksforgeeks.org/problems/nuts-and-bolts-problem0431/1

class Solution
{
public:
    void matchPairs(char nuts[], char bolts[], int n)
    {
        vector<char> order = {'!', '#', '$', '%', '&', '*', '@', '^', '~'};
        set<int> nutsSet;

        for(int i = 0; i < n; i++)
            nutsSet.insert(nuts[i]);

        int index = 0;
        for(char &c: order)
        {   
            if(nutsSet.find(c) != nutsSet.end())
            {
                nuts[index] = c;
                bolts[index] = c;
                index++;
            }
        }
    }
};