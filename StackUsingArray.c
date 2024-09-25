// Stack Implementation using an array

#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int data) {
  if (top == MAX - 1) {

    printf("Stack Overflow \n");
  }
  stack[++top] = data;
  printf("%d pushed to stack\n", data);
}

void pop() {

  if (top == -1) {
    printf("Stack Underflow\n");
    return;
  }

  printf("%d popped from stack\n", stack[top--]);
}

void display() {
  if (top == -1) {
    printf("Stack is empty\n");
    return;
  }
  printf("Stack element: ");
  for (int i = top; i >= 0; i--) {
    printf("%d ", stack[i]);
  }
  printf("\n");
}

int main() {
  push(50);
  push(90);
  push(30);
  display();
  pop();
  display();
  return 0;
}
