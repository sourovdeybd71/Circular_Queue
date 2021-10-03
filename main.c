#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define sz 10
int num_array[sz];
int front = -1;
int rear = -1;

bool isEmpty(){
  if(front == -1)
      return true;
  return false;
}
bool isFull(){
  if((front==0 && rear == sz-1) || (rear==front-1)){
    return true;
  }
  return false;
}
void enqueue(int data) {

    if(isFull()){
        printf("Overflow\n");
        return;
    }

    if(front==-1){
        front = 0;
    }

    if(rear == sz-1) {
        rear = 0;
    }
    else
        rear += 1;

    num_array[rear] = data;
}


int dequeue() {
    if(isEmpty()){
        printf("Underflow!! \n");
        return NULL;
    }

    int data = num_array[front];

    if(front == rear){
        front = rear = -1;
    }

    else if(front == sz-1) {
        front = 0;
    }
    else
        front += 1;

    return data;
}



int main(void) {
  int i, n, num;

  printf("Enqueue (1) or Dequeue (2): ");
  while (scanf("%d", &i)==1){
    if(i==1){
      printf("(Enqueue) Enter a number: ");
      scanf("%d", &num);
      enqueue(num);

      printf("Front: %d, Rear: %d", front, rear);

    }
    else if(i==2){
      num= dequeue();
      if(num!=NULL)
            printf("Deleted item: %d", num);
      printf("\nFront: %d, Rear: %d", front, rear);
    }
    printf("\n\nEnqueue (1) or Dequeue (2): ");
  }
}