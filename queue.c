#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
  int data;
  struct Queue *link;
} Node;

Node *createNode()
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->link = NULL;
}
int isQueueEmpty(Node *rearEnd)
{
  return rearEnd->link == NULL;
}
void enqueue(int newData, Node *rearEnd)
{
  Node *newNode = createNode();
  newNode->data = newData;
  newNode->link = rearEnd->link;
  rearEnd->link = newNode;
}
void dequeue(Node *rearEnd)
{
  if (isQueueEmpty(rearEnd))
  {
    printf("The Queue is empty");
  }
  else
  {
    while (rearEnd->link->link != NULL)
    {
      rearEnd = rearEnd->link;
    }
    free(rearEnd->link);
    rearEnd->link = NULL;
  }
}
void getRear(Node *rearEnd)
{
  printf("\n The element in the rear end is : %d \n", rearEnd->link->data);
}
void getFront(Node *rearEnd)
{
  while (rearEnd->link != NULL)
  {
    rearEnd = rearEnd->link;
  }
  printf("\n The element in the front end is : %d \n", rearEnd->data);
}
void printQueue(Node *rearEnd)
{
  while (rearEnd != NULL)
  {
    printf("->%d", rearEnd->link->data);
    rearEnd = rearEnd->link;
  }
}
int main()
{
  Node *rearEnd = createNode();
  enqueue(5, rearEnd);
  enqueue(10, rearEnd);
  enqueue(15, rearEnd);
  dequeue(rearEnd);
  enqueue(200, rearEnd);
  getRear(rearEnd);
  getFront(rearEnd);

  printQueue(rearEnd);
  return 0;
}