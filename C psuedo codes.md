# Linked Lists

## Single Linked Lists

### Node creation
```c
struct node{
    int data;
    struct node *next; 
}
// element Creation
struct node *first = (struct node*)malloc(sizeof(struct node )) 
struct node *second = (struct node*)malloc(sizeof(struct node))
struct node *third = (struct node*)malloc(sizeof(struct node))

first->data=1; // Storing data
first->next=second; //Pointing to next element

second->data=2;
second->next=third;
third->data=3;
third ->next = NULL;

```
### Displaying the elements of a Linked list
```c
struct node *t = first;
while(t!=NULL){
    printf("%d" t->data);
    t=t->next;
}
```

### Inserting at beginning 
```c
struct node *t = (struct node*)malloc(sizeof(struct node))
t->data =x
t->next= first
first=t
```

### Inserting at given Pos

```c
int pos= x
struct node *t = (struct node*)malloc(sizeof(struct node))
t->data =x
struct node *p = first
for(int i=0;i<pos-1;i++){
    p=p->next;
}
t->next=p->next
p->next=t
```

### Deleting at beg

```
struct node *temp=head;
head = temp->next;
free(temp)
```

### Deleting at given pos
```c
struct node *p;
struct node *q=head;
for(int i=0;i > pos-1;i++){
p=q;
q=q->next;
}
if(q){
p->next= q->next;
free(q);
}
```

## Double Linked List

### Creating the nodes

```c
void addNode(int num) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = num;
  newNode->next = 0;
  newNode->prev = 0;
  if (head == NULL) {
    head = tail = newNode;
  } else {
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
  }
}
```

### Insertion at the beginning
```c
void insertAtBeg(int num) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = num;
  newNode->next = 0;
  newNode->prev = 0;
  head->prev = newNode;
  newNode->next = head;
  head = newNode;
}
```
### Inserting at a given Position
```c
void insertAtGivenPos(int num, int pos) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = num;
  newNode->prev = 0;
  newNode->next = 0;
  if (pos == 1) {
    insertAtBeg(num);
  } else {
    struct node *temp = head;
    for (int i = 0; i > pos - 1; i++) {
      temp = temp->next;
    }
    newNode->prev = temp;
    newNode->next = temp->next;
    temp->next = newNode;
    newNode->next->prev = newNode;
  }
}
```
## Circular Linked List

### Node Creation 
```c
void createCll(int num) {

  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = num;
  newNode->next = NULL;
  if (head == NULL) {
    head = newNode;
    newNode->next = head;
  } else {
    struct node *temp = head;
    while (temp->next != head) {
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
  }
}
```

### Displaying elements in Circular LL

```c
void display() {
  struct node *temp = head;
  if (temp == NULL) {
    printf("\nList is empty\n");
  } else {
    printf("\nElements are\n");
    do {
      printf("\n%d\n", temp->data);
      temp = temp->next;
    } while (temp != head);
  }
}
```
# Stack

## Stack Using array with Push and pop 
```c
#include <stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int num) {

  if (top == MAX - 1) {
    printf("Stack overflow");
  } else {
    top++;
    stack[top] = num;
    printf("\n%d element pushed to stack\n", num);
  }
}
void pop() {

  if (top == -1) {

    printf("Stack Underflow");
  } else {
    top--;
    printf("Element popped");
  }
}
void peek() {
  if (top == -1) {
    printf("Top is empty");
  } else {
    printf("\n%d is at top\n", stack[top]);
  }
}

void display() {
  if (top == -1) {
    printf("Stack is empty");
  } else {
    printf("\nElements of stack are\n");
    for (int i = top; i >= 0; i--) {

      printf("\n%d\n", stack[i]);
    }
  }
}

int main() {
  push(10);
  push(20);
  push(30);
  pop();
  peek();

  display();

  return 0;
}
```
## Stack Using Linked List

```c
#include <stdio.h>
#include <stdlib.h>

struct node {

  struct node *next;
  int item;
};

struct node *top = 0;

void push(int num) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->item = num;
  newNode->next = top;
  top = newNode;
  printf("\n%d element pushed\n", num);
}
void pop() {
  struct node *temp = top;
  if (temp == 0) {
    printf("\nStack underflow\n");
  } else {
    top = temp->next;
    free(temp);
  }
}

void peek() {
  struct node *temp = top;
  if (top == 0) {
    printf("\nStack is empty\n");
  } else {
    printf("\n%d is at the top\n", temp->item);
  }
}
void display() {

  struct node *temp = top;
  if (temp == 0) {
    printf("\nStack is empty\n");
  } else {
    printf("\nElements of stack are\n");
    while (temp != 0) {
      printf("\n%d\n", temp->item);
      temp = temp->next;
    }
  }
}

int main() {

  push(10);
  push(20);
  push(30);
  pop();
  peek();
  display();
}
```
# Queue

## Queue Using Array

```c
#include <stdbool.h>
#include <stdio.h>

#define MAX 5

int rear = -1, front = -1;
int queue[MAX];

void enqueue(int x) {

  if (rear == MAX - 1) {
    printf("\nOverflow\n");
  } else if (rear == -1 && front == -1) {
    rear = front = 0;
    queue[rear] = x;
    printf("\n%d item enqueued\n", x);

  } else {
    rear++;
    queue[rear] = x;
    printf("\n%d item enqueued\n", x);
  }
}
void dequeue() {
  if (rear == -1 && front == -1) {
    printf("\nUnderflow\n");
  } else if (rear == front) {
    front = rear = -1;
    printf("\nitem dequeued\n");

  } else {
    front++;
    printf("\nitem dequeued\n");
  }
}
void display() {

  if (rear == -1) {
    printf("\nQueue is empty\n");
  } else {
    for (int i = front; i < rear + 1; i++) {
      printf("\n%d\n", queue[i]);
    }
  }
}

void peek() {
  if (rear == -1 && front == -1) {
    printf("\nQueue is empty\n");
  } else {
    printf("\n%d is at front\n", queue[front]);
  }
}
bool isEmpty() {
  if (rear == -1 && front == -1)
    return true;
  else
    return false;
}

bool isFull() {
  if (rear == MAX - 1)
    return true;
  else
    return false;
}

int main() {

  enqueue(10);
  enqueue(20);
  enqueue(30);
  enqueue(40);
  enqueue(50);
  display();
  peek();
}
```


## Queue using Linked List

```c
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node {

  struct node *next;
  int data;
};

struct node *head = 0;
struct node *tail = 0;

void enqueue(int x) {

  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = x;
  newNode->next = 0;

  if (head == 0 && tail == 0) {
    head = tail = newNode;
    printf("\n%d element enqueued\n", x);
  } else {
    tail->next = newNode;
    tail = newNode;
    printf("\n%d element enqueued\n", x);
  }
}

void display() {
  struct node *temp = head;
  if (head == 0 && tail == 0) {
    printf("\nQueue is empty\n");
  } else {
    printf("\nElements in the queue are\n");
    while (temp != 0) {
      printf("\n%d\n", temp->data);
      temp = temp->next;
    }
  }
}
void dequeue() {
  struct node *temp = head;

  if (temp == 0) {
    printf("\nUnderflow\n");
  } else {

    head = temp->next;
    free(temp);
    printf("\nElement dequed\n");
  }
}
void peek() {
  if (head == 0 && tail == 0) {
    printf("\nQueue is empty\n");
  } else {
    printf("\n%d is at the top\n", head->data);
  }
}

int main() {

  enqueue(10);
  enqueue(20);
  dequeue();
  enqueue(30);
  enqueue(40);
  display();
  peek();
}
```





