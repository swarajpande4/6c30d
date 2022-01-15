// Prerequisite tasks: https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1/

/*
    Intuition: 
    1.  We can consider this as a graph problem. All tasks are nodes of the graph, and if a task (say u) is a 
        prerequisite of another task (say v), we will add a directed edge from node u to node v.
    2.  Later we can find if a cycle exists in this generated directed graph. If cycle exists, then it will be 
        impossible to do all the tasks. (No topological ordering)
*/

class Solution
{
public:
    // Returns adjacency list representation from a list of pairs
    vector<unordered_set<int>> makeGraph(int numTasks, vector<pair<int, int>> &prerequisites)
    {
        vector<unordered_set<int>> graph(numTasks);
        
        for(auto pre: prerequisites)
            graph[pre.second].insert(pre.first);
        
        return graph;
    }

    // A DFS based function to check wheter there exists a cycle in directed graph or not
    bool isCycle(vector<unordered_set<int>> &graph, int node, vector<bool> &path, vector<bool> &visited)
    {
        if(visited[node])
            return false;
        
        path[node] = visited[node] = true;

        for(int neighbour: graph[node])
            if(path[neighbour] || isCycle(graph, neighbour, path, visited))
                return true;
        
        path[node] = false;
        return false;
    }

    bool isPossible(int N, vector<pair<int, int>> &prerequisites)
    {
        vector<unordered_set<int>> graph = makeGraph(N, prerequisites);
        vector<bool> path(N, false);
        vector<bool> visited(N, false);

        for(int i = 0; i < N; i++)
            if(!visited[i] && isCycle(graph, i, path, visited))
                return false;
        
        return true;
    }
};