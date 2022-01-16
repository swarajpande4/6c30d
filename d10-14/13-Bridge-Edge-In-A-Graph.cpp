// Bridge edge in a graph: https://practice.geeksforgeeks.org/problems/bridge-edge-in-graph/1

class Solution
{
public:
    void dfs(int node, vector<bool> &visited, vector<int> adj[], int c, int d)
    {
        visited[node] = true;
        for(auto e: adj[node])
        {
            // Here we do not consider the edge (c, d) while doing dfs and 
            // marking nodes as visited
            if((node == c && e == d) || (node == d && e == c))  
                continue;
            
            if(!visited[e])
                dfs(e, visited, adj, c, d);
        }
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<bool> visited(V, false);
        dfs(c, visited, adj, c, d);         // We call dfs from the cth node
        
        // If we are unable to reach node d, while ignoring the edge(c, d) using dfs
        // the edge(c, d) is definitely a bridge edge.
        if(!visited[d])                 
            return 1;
        
        return 0;
    }
}