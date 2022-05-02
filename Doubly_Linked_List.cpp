#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node;

// Global Declaration of InsertAtHead Function,, Not nessecary|
void insertAtHead(node *&, int);

// Doubly Linked List Class
class node
{
public:
    int data;
    node *next;
    node *prev;
    // Constructor
    node(int val)
    {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

// InsertAtHead
void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;

    if (head != NULL)
    {
        head->prev = n;
    }
    head = n;
}

// InsertAtTail

void insertAtTail(node *&head, int val)
{
    if (head == NULL)
    {
        insertAtHead(head, val);
        return;
    }

    node *n = new node(val);
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->prev = temp;
    n->next = NULL; // Automatically point to NULL by Constructor
}

// Display all the values of Doubly Linked List

void display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Deletion of Double Linked List

// DeleteAtHeadFUnction

void deleteAtHead(node *&head)
{
    node *todelete = head;
    head = head->next;
    head->prev = NULL;

    delete todelete;
}

void deletion(node *&head, int pos)
{
    if (pos == 1)
    {
        deleteAtHead(head);
        return;
    }
    node *temp = head;
    int count = 1;

    while (temp != NULL && count != pos)
    {
        temp = temp->next;
        count++;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    delete temp;
}

// find Length of Doubly linked list
int length(node *head)
{
    int l = 0;
    node *temp = head;
    while (temp != NULL)
    {
        l++;
        temp = temp->next;
    }
    return l;
}
// Append Last k nodes of A Linked List
// input - 1,2,3,4,5,6,7,8,9  then kappend(head,7) output- 3,4,5,6,7,8,9,1,2 |
node *kappend(node *&head, int k)
{
    node *newHead;
    node *newTail;
    node *tail = head;

    int l = length(head);
    k = k % l;
    int count = 1;
    while (tail->next != NULL)
    {
        if (count == l - k)
        {
            newTail = tail;
        }
        if (count == l - k + 1)
        {
            newHead = tail;
        }
        tail = tail->next;
        count++;
    }
    newTail->next = NULL;
    tail->next = head;

    return newHead;
}

// intersect
// 23->223->253->236->213->256->NULL
// 293->203->2153->NULL
// 23->223->253->236->213->256->NULL
// 293->203->2153->213->256->NULL

void intersect(node *&head1, node *&head2, int pos)
{
    node *temp1 = head1;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }
    node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

// Find intersection point of 2 linked list
// 213

int intersection(node *&head1, node *&head2)
{
    int l1 = length(head1);
    int l2 = length(head2);
    int d = 0;
    node *ptr1;
    node *ptr2;

    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1;
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }

    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return -1;
}

// Merge 2 Sorted linked List
node *merge(node *&head1, node *&head2)
{
    node* p1 = head1;
    node* p2 = head2;
    node* n = new node(-1);   //Here n denotes head 
    node* p3 = n;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data < p2->data)
        {
            p3->next = p1;
            p1 = p1->next;
        }
        else
        {
            p3->next = p2;
            p2 = p2->next;
        }
        p3 = p3->next;
    }

    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }

    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return n->next;
}

// Merge Via Recursion

node* mergeRecursive(node* &head1,node* &head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }

    node* result;
    if(head1->data<head2->data){
        result=head1;
        result->next=mergeRecursive(head1->next,head2);
    }
    else{
        result=head2;
        result->next=mergeRecursive(head1,head2->next);
    }

    return result;

}

int main()
{
    node *head = NULL;
    // insertAtHead(head,34);
    // insertAtHead(head,344);
    // insertAtHead(head,364);
    // insertAtHead(head,374);
    // insertAtHead(head,34);
    // insertAtHead(head,364);
    // insertAtHead(head,34);
    // insertAtHead(head,384);
    // display(head);
    // deletion(head,5);
    // display(head);
    // cout<<length(head);
    // int arr[]={57,29,34,24,85,06,17,88,79};
    // for(int i=0;i<9;i++){
    //     insertAtTail(head,arr[i]);
    // }

    // display(head);
    // node* newHead=kappend(head,7);
    // display(newHead);
    node *head1 = NULL;
    node *head2 = NULL;
    insertAtTail(head1,2);
    insertAtTail(head1, 4);
    insertAtTail(head1,8 );
    insertAtTail(head1, 34);
    insertAtTail(head2, 7);
    insertAtTail(head2, 22);
    insertAtTail(head2, 52);
    display(head1);
    display(head2);
    // intersect(head1, head2, 5);
    // display(head1);
    // display(head2);
    // cout << intersection(head1, head2);
    //  display(merge(head1,head2));
    // display(mergeRecursive(head1,head2));

    return 0;
}
