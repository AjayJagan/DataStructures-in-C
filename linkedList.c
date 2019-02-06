#include <stdio.h>
#include <stdlib.h>

typedef struct List
{
    int data;
    struct List *next;
} Node;

struct List *createNode()
{
    Node *t = (Node *)malloc(sizeof(Node));
    t->next = NULL;
    return t;
}
void addFront(int newData, Node *head)
{
    Node *newNode = createNode();
    newNode->data = newData;
    newNode->next = head->next;
    head->next = newNode;
}
void addBack(int newData, Node *head)
{
    Node *newNode = createNode();
    Node *tailNode = head->next;
    while (tailNode->next != NULL)
    {
        tailNode = tailNode->next;
    }
    newNode->data = newData;
    newNode->next = NULL;
    tailNode->next = newNode;
}
void insertAfter(int num, int newData, Node *head)
{
    Node *newNode = createNode();
    Node *firstNode = head;
    newNode->data = newData;
    while (firstNode->next != NULL)
    {
        if (firstNode->data == num)
        {
            break;
        }
        firstNode = firstNode->next;
    }
    newNode->next = firstNode->next;
    firstNode->next = newNode;
}
void insertBefore(int num, int newData, Node *head)
{
    Node *newNode = createNode();
    Node *firstNode = head->next;
    if (firstNode->data == num)
    {
        addFront(newData, head);
    }
    else
    {
        while (firstNode->next != NULL)
        {
            if (firstNode->next->data == num)
            {
                break;
            }
            firstNode = firstNode->next;
        }

        newNode->data = newData;
        newNode->next = firstNode->next;
        firstNode->next = newNode;
    }
}

void deleteFront(Node *head)
{
    Node *firstNode = head->next;
    head->next = firstNode->next;
    free(firstNode);
}
void deleteBack(Node *head)
{
    Node *beforeTailNode = head->next;
    while (beforeTailNode->next->next != NULL)
    {
        beforeTailNode = beforeTailNode->next;
    }
    free(beforeTailNode->next);
    beforeTailNode->next = NULL;
}
void deleteNum(int num, Node *head)
{
    Node *beforeNode=head->next;
    if(beforeNode->data==num){
        deleteFront(head);
    }
    else{
        while(beforeNode!=NULL){
            if(beforeNode->next->data==num){
                break;
            }
            beforeNode=beforeNode->next;
        }
       beforeNode->next=beforeNode->next->next;
    }
   
}
void printList(Node *head)
{
    Node *firstNode = head->next;
    while (firstNode != NULL)
    {
        printf("->%d", firstNode->data);
        firstNode = firstNode->next;
    }
}
int main()
{
    Node *head = createNode();
    addFront(5, head);
    addFront(10, head);
    addBack(20, head);
    addBack(40, head);
    insertAfter(6, 95, head);
    insertBefore(6, 111, head);
    deleteNum(10,head);
    printList(head);
    return 0;
}