// Maximum 10 numbers in a list of 10M numbers.

// In the following solution, we will show the max 10 numbers in the list. 
// This solution, will not store distinct 10 maximums, rather it will return 
// just the max 10 numbers.

// If required, we may use set container in STL, to store and 
// finally return the distinct 10 maximums in the list.

// Here we use a min-heap to keep track of max 10 numbers. 
// Whenever we scan a element in list greater than the top of heap,
// we simply pop the element and push the scanned element.

// The worst case complexity of this solution is O(n * log (10)) 
// Which is better than sorting it, which would be O(n * log(n))

#include <bits/stdc++.h>
using namespace std;

vector<int> max10(vector<int> arr)
{
    priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.begin() + 10);

    for(int i = 10; i < arr.size(); i++)
    {
        if(pq.top() < arr[i])
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }

    vector<int> res;
    while(!pq.empty())
    {
        res.push_back(pq.top());
        pq.pop();
    }

    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x: arr)
        cin >> x;
    
    vector<int> max = max10(arr);

    for(int x: max)
        cout << x << " ";
    cout << endl;

    return 0;
}