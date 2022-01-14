// Count number of subtrees having given sum: https://practice.geeksforgeeks.org/problems/count-number-of-subtrees-having-given-sum/1/

int countSubtreesWithSumXUtil(Node *root, int &count, int X)
{
    if(!root)
        return 0;

    // Sum of nodes in left subtree
    int ls = countSubtreesWithSumXUtil(root -> left, count, X);
    
    // Sum of nodes in right subtree
    int rs = countSubtreesWithSumXUtil(root -> right, count, X);

    int sum = ls + rs + root -> data;

    if(sum == X)
        count++;
    
    // This utility function will return the sum of the subtree
    return sum;
}

int countSubtreesWithSumX(Node* root, int X)
{
	if(!root)
        return 0;

    int count = 0;

    // Sum of nodes in left subtree
    int ls = countSubtreesWithSumXUtil(root -> left, count, X);
    
    // Sum of nodes in right subtree
    int rs = countSubtreesWithSumXUtil(root -> right, count, X);

    if((ls + rs + root -> data) == X)
        count++;
    
    return count;
}