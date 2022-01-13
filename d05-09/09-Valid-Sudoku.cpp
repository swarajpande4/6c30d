// Valid Sudoku: https://practice.geeksforgeeks.org/problems/is-sudoku-valid4820/1/

class Solution
{
public:
    bool isValid(vector<vector<int>> mat)
    {
        int  rowCheck[9][9] = {0};          // rowCheck[4][0] means whether number 1 in row 4 has appeared or not
        int  colCheck[9][9]={0};            // colCheck[3][8] means whether number 9 in col 3 has appeared or not
        int blockCheck[3][3][9] = {0};      // blockCheck[0][2][5] means whether number 6 has appeared in block 0,2 (row 0-2, col 6-8)

        for(int r = 0; r < 9; r++)
        {
            for(int c = 0; c < 9; c++)
            {
                if(mat[r][c] != 0)
                {
                    int number = mat[r][c] - 1;     // number's index
                    
                    if(rowCheck[r][number]++)       // If the number has already appeared once, return false.
                        return 0;
                    
                    if(colCheck[c][number]++)
                        return 0;
                    
                    if(blockCheck[r/3][c/3][number]++)
                        return 0;
                }
            }
        }

        return 1;
    }
};