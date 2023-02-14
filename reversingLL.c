#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *link;
    int info;
}node;
node *create_list(node *start);
node *addtoempty(node *start, int data);
node *addatend(node *start, int data);
node *reverse_list(node *start);
void display(node *start);

int main(){
    node *start = NULL;
    int choice;

    while(1){
        printf("1:Create the list\n");
        printf("2:Reverse the list\n");
        printf("3:Display\n");
        printf("4:Exit\n");

        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch(choice){

            case 1: 
                 start = create_list(start);
                break;
            case 2:  start = reverse_list(start);
                break;
            case 3: display(start);
                break;
            case 4: exit(1);
                break;
            default:
                printf("Invalid choice!\n");
                break;
        }
    }

    return 0;
}

node *create_list(node *start){
    int i,n, data;
    printf("Enter number of nodes in the list:\n");
    scanf("%d", &n);
    start = NULL;
    if(n == 0){
        return start;
    }
    printf("Enter the element to be inserted:\n");
    scanf("%d", &data);
    start = addtoempty(start, data);
    for(i=2; i<=n; i++){
        printf("Enter the element to be inserted:\n");
        scanf("%d", &data);
        start = addatend(start, data);
    }
    return start;
}

node *addtoempty(node *start, int data){
    node *tmp = (node *)malloc(sizeof(node));
    tmp -> info = data;
    start = tmp;
    tmp -> link = NULL;
    return start;
}

node *addatend(node *start, int data){
    node *tmp, *p;
    tmp = (node *)malloc(sizeof(node));
    tmp ->info = data;
    p = start;
    while(p->link != NULL){
        p = p -> link;
    }
    p -> link = tmp;
    tmp -> link = NULL;
    return start;
}

void display(node *start){
    if(start == NULL){
        printf("The list is empty!\n");
        return;
    }
    node *p = start;
    while(p != NULL){
        printf("%d\t", p->info);
        p = p ->link;
    }
    printf("\n\n");
}

node *reverse_list(node *start){
    node *prev, *ptr, *next;
    prev = NULL;
    ptr = start;

    while(ptr != NULL){
        next = ptr -> link;
        ptr -> link = prev;
        prev = ptr;
        ptr = next;
    }
    start = prev;
    return start;

}