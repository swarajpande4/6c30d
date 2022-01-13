// Rotate by 90 degree: https://practice.geeksforgeeks.org/problems/rotate-by-90-degree0356/1/

/* matrix : given input matrix, you are require
 to change it in place without using extra space */

void rotate(vector<vector<int>> &matrix)
{
    // First we rotate individual rows
    for (auto &row : matrix)
        reverse(row.begin(), row.end());

    // Finally we transpose our matrix
    for (int i = 0; i < matrix.size(); i++)
        for (int j = i; j < matrix[0].size(); j++)
            swap(matrix[i][j], matrix[j][i]);
}