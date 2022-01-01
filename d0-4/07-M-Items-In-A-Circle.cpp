// m-Items in a circle: https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1
class Solution
{
public:
    int findPosition(int N, int M, int K)
    {
        /*
        M + K = If they are in straight line,
        -1 for the first item for current child and
        % N for the circle.
        */

        int n = (M + K - 1) % N;
        if(n == 0)
            return N;
        
        return n;
    }
};