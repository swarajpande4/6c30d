// Decode The String: https://practice.geeksforgeeks.org/problems/decode-the-string2444/1

class Solution
{
public:
    string decodedString(string s)
    {
        stack<int> count;
        stack<string> result;

        int index = 0;
        string currString = "";

        while(index < s.length())
        {
            if(isdigit(s[index]))
            {
                int num = 0;
                while(isdigit(s[index]))
                {
                    num = 10 * num + (s[index] - '0');
                    index++;
                }

                count.push(num);
            }
            
            else if(s[index] == '[')
            {
                result.push(currString);
                currString = "";
                index++;
            }

            else if(s[index] == ']')
            {
                int n = count.top();
                count.pop();

                string res = result.top();
                result.pop();

                for(int i = 0; i < n; i++)
                    res += currString;
                
                currString = res;
                index++;
            }

            else 
            {
                currString += s[index];
                index++;
            }
        }

        return currString;
    }
};