#include <bits/stdc++.h>
using namespace std;

/* Link list node */
class Node
{
public:
    int data;
    Node *next;
};

Node *reverse(Node *head, int k)
{
    // base case
    if (!head)
        return NULL;
    Node *current = head;
    Node *next = NULL;
    Node *prev = NULL;
    int cnt = 0;

    /*reverse first k nodes of the linked list */
    while (current != NULL && cnt < k)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        cnt++;
    }

    if (next != NULL)
        head->next = reverse(next, k);
    return prev;
}

/* UTILITY FUNCTIONS */

void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* Function to print linked list */
void print(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

/* Driver code*/
int main()
{
    Node *head = NULL;

    /* Created Linked list
     1->2->3->4->5->6->7->8->9->10 */
    push(&head, 10);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Given linked list \n";
    print(head);
    head = reverse(head, 4);

    cout << "\nReversed Linked list \n";
    printList(head);

    return (0);
}
