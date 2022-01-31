// Transform to sum tree: 

/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution 
{
public: 
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        if(!node)
            return;
        
        node -> data = 0;

        if(node -> left)
        {
            node -> data += node -> left -> data;
            toSumTree(node -> left);                    // Recursive call
            node -> data += node -> left -> data;       // Now also include the updated value
        }

        if(node -> right)
        {
            node -> data += node -> right -> data;
            toSumTree(node -> right);                   // Recursive call
            node -> data += node -> right -> data;      // Now also include the updated value
        }
    }

};
