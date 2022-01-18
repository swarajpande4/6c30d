// Implement Atoi: https://practice.geeksforgeeks.org/problems/implement-atoi/1/

class Solution
{
public:
    int atoi(string str)
    {
        int result = 0, sign = 1;
        int i = 0;

        if (str[i] == '-')
        {
            sign = -1;
            i++;
        }

        while (str[i])
        {
            // If any characters is not an integer, we simply return -1
            if (!(str[i] - '0' >= 0 && str[i] - '0' <= 9))
                return -1;
            
            // else we add the number in our result
            result = result * 10 + str[i] - '0';
            i++;
        }

        return sign * result;
    }
};