// Tree serialization and deserialization: https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1

/* A binary tree node has data, pointer to left child
    and a pointer to right child

struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution
{
public:
    void inOrder(Node *node, vector<int> &res)
    {
        if (node == NULL)
        {
            res.push_back(-1);
            return;
        }

        res.push_back(node->data);
        inOrder(node->left, res);
        inOrder(node->right, res);
    }

    // Function to serialize a tree and return a list containing nodes of tree.
    vector<int> serialize(Node *root)
    {
        vector<int> res;
        inOrder(root, res);
        return res;
    }

    // Function to construct the tree
    Node *construct(vector<int> &a, int *index)
    {
        // If there are no elements in the list
        if (*index == a.size() || a[*index] == -1)
        {
            *index += 1;
            return NULL;
        }

        // Creating new node for storing the current element
        Node *root = new Node(a[*index]);
        *index += 1;

        // Calling function recursively for left and right subtrees
        root->left = construct(a, index);
        root->right = construct(a, index);

        return root;
    }

    // Function to deserialize a list and construct the tree.
    Node *deSerialize(vector<int> &A)
    {
        int index = 0;
        return construct(A, &index);
    }
};