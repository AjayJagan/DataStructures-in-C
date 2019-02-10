#include <stdio.h>
#include <stdlib.h>

typedef struct DList
{
  int data;
  struct DList *previous;
  struct DList *next;
} Node;

Node *createNode()
{
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->previous = NULL;
  newNode->next = NULL;
  return newNode;
}
void addFront(int newData, Node *head)
{
  Node *newNode = createNode();
  newNode->data = newData;
  if (head->next == NULL)
  {
    newNode->previous = head;
    head->next = newNode;
  }
  else
  {
    newNode->previous = head;
    newNode->next = head->next;
    head->next->previous = newNode;
    head->next = newNode;
  }
}
void addBack(int newData, Node *head)
{
  Node *newNode = createNode();
  newNode->data = newData;
  while (head->next != NULL)
  {
    head = head->next;
  }
  head->next = newNode;
  newNode->previous = head;
}
void insertBefore(int newData, int num, Node *head)
{
  Node *newNode = createNode();
  newNode->data = newData;
  while (head->next != NULL)
  {
    if (head->data == num)
    {
      break;
    }
    head = head->next;
  }
  newNode->next = head;
  newNode->previous = head->previous;
  head->previous->next = newNode;
  head->previous = newNode;
}
void insterAfter(int newData, int num, Node *head)
{
  Node *newNode = createNode();
  newNode->data = newData;
  while (head->next != NULL)
  {
    if (head->data == num)
    {
      break;
    }
    head = head->next;
  }
  newNode->next = head->next;
  newNode->previous = head;
  head->next->previous = newNode;
  head->next = newNode;
}
void pop(Node *head)
{
  while (head->next != NULL)
  {
    head = head->next;
  }
  head->previous->next = NULL;
  head->previous = NULL;
  free(head);
}
void shift(Node *head)
{
  if (head->next != NULL) {
    Node *t = head->next;
    free(t);
    head->next = head->next->next;
    head->next->previous = head;
  }
}
void deleteNum(int num, Node *head)
{
  while (head->next != NULL)
  {
    if (head->data == num)
    {
      break;
    }
    head = head->next;
  }
  head->next->previous = head->previous;
  head->previous->next = head->next;
  head->next = NULL;
  head->previous = NULL;
  free(head);
}
void printList(Node *head)
{
  while (head != NULL)
  {
    printf("<=>%d", head->next->data);
    head = head->next;
  }
}
int main()
{
  Node *head = createNode();
  addBack(1, head);
  addFront(5, head);
  addFront(10, head);
  //addFront(15, head);
  //addFront(20, head);
  addBack(2, head);
  addBack(3, head);
  insertBefore(111, 10, head);
  insterAfter(222, 5, head);
  pop(head);
  deleteNum(10, head);
  shift(head);
  // /addFront(555, head);
  printList(head);
  return 0;
}