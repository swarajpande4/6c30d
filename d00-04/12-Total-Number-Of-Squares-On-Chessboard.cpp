// Given a chessboard of size n*n, print the total sqaures inside the chessboard.
#include <bits/stdc++.h>
using namespace std;

// Count = 1**2 + 2**2 + 3**2 + ... n**2
int sqaures(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++)
        count += i * i;

    return count;
}

// Count = (n*(n+1)/2) * (2*n + 1)/3
int efficientSquares(int n)
{
    return (n * (n + 1) / 2) * (2 * n + 1) / 3;
}

int main()
{
    int n;
    cin >> n;

    // cout << sqaures(n) << "\n";
    cout << efficientSquares(n) << "\n";

    return 0;
}