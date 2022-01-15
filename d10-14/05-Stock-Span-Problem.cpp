// Stock span problem: https://practice.geeksforgeeks.org/problems/stock-span-problem-1587115621/1

class Solution
{
public:
    vector<int> calculateSpan(int *price, int n)
    {
        stack<int> s;
        
        s.push(0);
        vector<int> span(n);

        // Span value of first day is always 1
        span[0] = 1;

        for(int i = 1; i < n; i++)
        {
            // We pop elements from stack until the price at the top of stack
            // is less than or equal to current price.
            while(!s.empty() && price[s.top()] <= price[i])
                s.pop();
            
            // If stack becomes empty, then price[i] is greater than all elements
            // on the left of it, so span is i + 1.
            // Otherwise, price[i] is greater than elements after value at top of stack.
            int spanValue;
            if(s.empty())
                spanValue = i + 1;
            else 
                spanValue = i - s.top();
            
            span[i] = spanValue;
            
            // Push this element onto the stack
            s.push(i);
        }

        return span;
    }
};