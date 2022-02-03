// Power of numbers: 
#define mod 1000000007
class Solution 
{
public:

    long long modfunc(long long n, long long r)
    {
        if(n == 0)
            return 0;
        
        if(r == 0)
            return 1;
        
        long long y;

        // If r is odd
        if(r % 2 == 0)
        {
            y = modfunc(n, r / 2);
            y = (y * y) % mod;
        }
        else 
        {
            y = n % mod;
            y = (y * modfunc(n, r - 1) % mod) % mod;
        }

        return (y + mod) % mod;
    }

    long long power(int N, int R)
    {
        return modfunc(N, R) % mod;
    }
};