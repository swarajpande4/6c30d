// Generate Binary Numbers: https://practice.geeksforgeeks.org/problems/generate-binary-numbers-1587115620/1/#

// Function to generate binary numbers from 1 to N using a queue.
vector<string> generate(int N)
{
    vector<string> ans;

    for (int i = 1; i <= N; i++)
    {
        string s = "";
        int num = i;

        while (num)
        {
            int bit = num % 2;
            s = to_string(bit) + s;
            num /= 2;
        }

        ans.push_back(s);
    }

    return ans;
}