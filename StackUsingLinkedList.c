// Stack Implementation Using a Linked List

#include <stdio.h>
#include <stdlib.h>
struct Node {
  int data;
  struct Node *next;
};

struct Node *top = NULL;

void push(int data) {

  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  if (!temp) {
    printf("Heap Overflow");
    return;
  }
  temp->data = data;
  temp->next = top;
  top = temp;
  printf("%d pushed to stack \n", data);
}

void pop() {
  if (top == NULL) {
    printf("Stack Underflow\n");
    return;
  }
  struct Node *temp = top;
  printf("%d popped from stack\n", top->data);
  top = top->next;
  free(temp);
}

void display() {

  if (top == NULL) {
    printf("Stack is empty \n");
    return;
  }

  struct Node *temp = top;
  printf("Stack element\n");

  while (temp != NULL) {
    printf("%d ", temp->data);
    temp = temp->next;
  }

  printf("\n");
}

int main() {
  push(60);
  push(30);
  push(10);
  push(15);
  display();
  pop();
  display();
  return 0;
}
