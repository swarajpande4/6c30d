// Number of boomerangs: https://leetcode.com/problems/number-of-boomerangs/

/*
    Intuition: 
    We fix a point, and then find distances of all the other points from that point, and push it into hashmap.
    Later we use simply use permutations and combinations to calculate the result.
*/

class Solution
{
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int ans = 0;

        for(auto p: points)
        {
            map<double, int> mp;

            auto x1 = p[0];
            auto y1 = p[1];

            for(auto pi: points)
            {
                if(p == pi)
                    continue;

                auto x2 = pi[0];
                auto y2 = pi[1];

                int xDist = (x1 - x2) * (x1 - x2);
                int yDist = (y1 - y2) * (y1 - y2);

                double finalDist = sqrt(xDist + yDist);

                mp[finalDist]++;
            }

            for(auto i: mp)
                if(i.second > 1)
                    ans += (i.second * (i.second - 1));
        }

        return ans;
    }
};