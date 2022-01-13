// Run Length Encoding: https://practice.geeksforgeeks.org/problems/run-length-encoding/1

string encode(string src)
{
    string res = "";

    char prev = src[0];
    int currFreq = 1;

    for (int i = 1; i < src.length(); i++)
    {
        if (src[i] == prev)
            currFreq++;
        else
        {
            res = res + prev + to_string(currFreq);
            currFreq = 1;
        }

        prev = src[i];
    }

    res = res + prev + to_string(currFreq);

    return res;
}