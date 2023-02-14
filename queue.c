#include <stdio.h>
#include <stdlib.h>
#define MAX 10
int queue[MAX];
int rear = -1;
int front = -1;

void enqueue(int item);
int dequeue();
int peek();
void display();
int check_if_full();
int check_if_empty();

int main(){
    int choice, item;

    while(1){
        printf("\t1. Enqueue\n");
        printf("\t2. Dequeue\n");
        printf("\t3. Display\n");
        printf("\t4. Peek at the queue\n");
        printf("\t5. Quit\n");

        printf("Enter your choice:");
        scanf("%d", &choice);

        switch(choice){

            case 1: printf("Enter something into the Queue(FIFO): ");
                    scanf("%d", &item);
                    enqueue(item);
                break;
            case 2: item = dequeue();
                    printf("Deleted item is [ %d ]\n", item);
                break;
            case 3: display();
                break;
            case 4: printf("Peeked element is: [ %d ]\n", peek());
                break;
            case 5:
                exit(1);
            default: 
                printf("Invalid choice!\n");

        }
    }

    return 0;
}

int check_if_full(){
    if(rear == MAX - 1)
        return 1;
    else    
        return 0;
}

int check_if_empty(){

    if(front == -1 || front == rear + 1)
        return 1;
    else    
        return 0;

}

void display(){
    int i;
    if(check_if_empty()){
        printf("Queue is empty! Nothing to display\n");
        return;
    }
    printf("Queue is:\n\n");
    
    for(i=front; i<=rear; i++){
        printf("%10d ", queue[i]);
    }
    printf("\n\n");

}

void enqueue(int item){
    if(check_if_full()){
        printf("Queue Overflow!\n");
        return;
    }
    if(front == -1)
        front = 0;
    rear = rear + 1;
    queue[rear] = item;
}

int dequeue(){
    int item;

    if(check_if_empty()){
        printf("Queue underflow! Cannot dequeue\n");
        exit(1);
    }

    item = queue[front];
    front = front + 1;
    return item;
}

int peek(){
    if(check_if_empty()){
        printf("Queue underflow!\n");
        exit(1);
    }

    return queue[front];
}