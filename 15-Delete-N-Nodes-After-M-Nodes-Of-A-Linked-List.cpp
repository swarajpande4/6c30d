// Delete N nodes after M nodes of a linked list: https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1/#

class Solution
{
public:
    void linkdelete(struct Node *head, int M, int N)
    {
        Node *t;
        Node *curr = head;

        while(curr)
        {
            // Skipping M nodes
            for(int i = 1; i < M && curr != NULL; i++)
                curr = curr -> next;
            
            // If we have reached the end of the linked list
            if(curr == NULL)
                return;
            
            t = curr -> next;

            // Delete N nodes 
            for(int i = 1; i <= N && t != NULL; i++)
            {
                Node *temp = t;
                t = t -> next;
                free(temp);
            }

            // Link the previous list with remaining nodes
            curr -> next = t;

            // Set current pointer for next iteration
            curr = t;
        }
    }
};