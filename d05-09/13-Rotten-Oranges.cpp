// Rotten Oranges: https://leetcode.com/problems/rotting-oranges/

class Solution 
{
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        if(grid.empty())
            return 0;

        int m = grid.size();            // number of rows
        int n = grid[0].size();         // number of columns
        int countFreshOranges = 0;      // count of fresh oranges

        queue<pair<int, int>> q;   // queue to store index of cell where rotten orages are placed

        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // count total number of oranges 
                if(grid[i][j] == 1)
                    countFreshOranges++;
                
                // pushing the rotten oranges inside the queue
                else if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        
        int minutes = 0;                                                    // to count number of minutes elapsed
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};    // four adjacent positions at which the oranged placed will get rotten
        
        while(countFreshOranges != 0 && !q.empty())
        {
            int qsize = q.size();       // we store q.size() in a variable, and use this variable in the loops, not q.size(), as the size of the queue keeps on changing
            
            for(int i = 0; i < qsize; i++)
            {
                int rottenI = q.front().first;
                int rottenJ = q.front().second;
                q.pop();

                for(auto d: dir)
                {
                    int newX = rottenI + d.first;
                    int newY = rottenJ + d.second;

                    // If we got any fresh orange adjacent to rotten orange, 
                    // then it will get rotten and count of fresh orange will decrease.
                    // Then we will push the new index of rotten orange in the queue.

                    if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1)
                    {
                        grid[newX][newY] = 2;
                        countFreshOranges--;
                        q.push({newX, newY});
                    }
                }
            }

            minutes++;
        }

        return countFreshOranges == 0 ? minutes : -1;
    }
};