// Burning Tree: https://practice.geeksforgeeks.org/problems/burning-tree/1/

class Solution
{
public:

    Node *bfsToMapParents(Node *root, map<Node *, Node *> &mpp, int start)
    {
        queue<Node *> q;        // To facilitate lever order traversal
        q.push(root);
        Node *res;              // To store the address of the start node

        while(!q.empty())
        {
            Node *node = q.front();
            if(node -> data == start)       // If start node found, we store its address
                res = node;
            q.pop();

            if(node -> left)                // If left child exists, then we make the node its parent
            {
                mpp[node -> left] = node;
                q.push(node -> left);
            }

            if(node -> right)               // If right child exists, then we make the node its parent
            {
                mpp[node -> right] = node;
                q.push(node -> right);
            }
        }

        return res;
    }

    int findMaxDistance(map<Node *, Node*> mpp, Node *targetNode)
    {
        queue<Node *> q;            // To facilitate BFS
        q.push(targetNode);

        map<Node *, int> vis;       // Visited array, to keep track whether a node is visited or not

        vis[targetNode] = 1;
        int maxi = 0;

        while(!q.empty())
        {
            int sz = q.size();          // We store the size of the queue, as it keeps changing
            int flag = 0;

            for(int i = 0; i < sz; i++)
            {
                auto node = q.front();
                q.pop();
                
                if(node -> left && !vis[node -> left])          // If the left child of the node is not visited
                {
                    flag = 1;
                    vis[node -> left] = 1;
                    q.push(node -> left);
                }

                if(node -> right && !vis[node -> right])        // If the right child of the node is not visited
                {
                    flag = 1;
                    vis[node -> right] = 1;
                    q.push(node -> right);
                }

                if(mpp[node] && !vis[mpp[node]])                // If the parent of the node is not visited    
                {
                    flag = 1;
                    vis[mpp[node]] = 1;
                    q.push(mpp[node]);
                }
            }

            if(flag)
                maxi++;
        }

        return maxi;
    }

    int minTime(Node *root, int target)
    {
        map<Node *, Node *> mpp;                                        // To store node to parent mapping
        Node *targetNode = bfsToMapParents(root, mpp, target);          
        int maxi = findMaxDistance(mpp, targetNode);
        return maxi;
    }
};