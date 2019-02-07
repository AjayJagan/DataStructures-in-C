#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
  int data;
  struct Stack *link;
} Node;

Node *createNode()
{
  Node *n = (Node *)malloc(sizeof(Node));
  n->link = NULL;
  return n;
}
int isEmpty(Node *base)
{
  return base->link == NULL;
}
void push(int newData, Node *base)
{
  Node *newNode = createNode();
  newNode->data = newData;
  while (base->link != NULL)
  {
    base = base->link;
  }
  base->link = newNode;
}
void pop(Node *base)
{
  if (isEmpty(base))
  {
    printf("The stack is Empty");
  }
  else
  {
    while (base->link->link != NULL)
    {
      base = base->link;
    }
    free(base->link);
    base->link = NULL;
  }
}

void peek(Node* base)
{ 
  while(base->link!=NULL){
    base=base->link;
  }
  printf("the top element is =>%d\n", base->data);
}
int printStack(Node *base)
{
  while (base != NULL)
  {
    printf("->%d", base->link->data);
    base = base->link;
  }
}
int main()
{
  Node *base = createNode();
  push(11, base);
  push(12, base);
  push(13, base);
  pop(base);
  pop(base);
  pop(base);
  push(14, base);
  push(15, base);
  push(16, base);
  push(17, base);
  push(18, base);
  peek(base);
  printStack(base);
  return 0;
}
