// Ugly Numbers: https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/

class Solution
{
public:
    ull getNthUglyNo(int n)
    {
        if(n >= 1 && n <= 5)
            return n;

        set<ull> s;
        s.insert(1);
        n--;

        while(n--)
        {
            ull top = *s.begin();
            s.erase(s.begin());

            s.insert(top * 2);
            s.insert(top * 3);
            s.insert(top * 5);
        }

        return *s.begin();
    }
};