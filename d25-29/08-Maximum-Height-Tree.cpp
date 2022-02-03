// Maximum Height Tree: https://practice.geeksforgeeks.org/problems/maximum-height-tree4803/1/

class Solution 
{
public: 
    int height(int N)
    {
        return (-1 + sqrt(1 + 8 * N)) / 2;
    }
};

/*
class Solution
{
public:
    int height(int N)
    {
        int x = sqrt(2 * N);
        
        if(N < (x * (x + 1)) / 2)
            x--;
        
        return x;
    }
};
*/