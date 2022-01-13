// Print anagrams together: https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/

/*
First we sort each word and then compare with other sorted words,
if other words match the word in sorted form, we add that word to the hashmap.
Finally we put each key's value vector in a vector of strings.
*/
class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        vector<vector<string>> result;
        unordered_map<string, vector<string>> m;

        for (int i = 0; i < string_list.size(); i++)
        {
            string word = string_list[i];
            sort(word.begin(), word.end());

            // Here we add the original string to the key which is the sorted string
            m[word].push_back(string_list[i]);
        }

        // Finally putting all values of the map in the result vector of vector of strings.
        for (auto p : m)
        {
            result.push_back(p.second);
        }

        return result;
    }
};