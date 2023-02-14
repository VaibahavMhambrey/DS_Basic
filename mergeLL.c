#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    struct node *link;
    int info;
}node;

node *create_list(node *start);
node *insert(node *start, int data);
node *insert_sorted(node *start, int data);
void merge(node *s1, node *s2);
void display(node *start);

node *create_list(node *start){

int i,n,data;

printf("Enter the number of nodes:");
scanf("%d", &n);

start = NULL;

for(i=1; i<=n; i++){
    printf("Enter the element to be inserted:");
    scanf("%d", &data);
    start = insert_sorted(start, data);
}
return start;

}

void display(node *start){
    node *p;
    if(start == NULL){
        printf("List is empty");
        return;
    }
    p = start;

    while(p!= NULL){
        printf("%d ", p->info);
        p = p ->link;
    }
    printf("\n");
}

node *insert(node *start, int data){

    node *p, *tmp;

    tmp = (node *)malloc(sizeof(node));

    tmp -> info = data;

    if(start == NULL){
        tmp -> link = start;
        start = tmp;
        return start;
    }
    else{
        p =start;
        while(p->link!=NULL){
            p = p -> link;
        }
        tmp -> link = p-> link;
        p->link = tmp;
    }
    return start;
}


node *insert_sorted(node *start, int data){

    node *ptr, *tmp;

    tmp = (node *)malloc(sizeof(node));

    tmp -> info = data;

    if(start == NULL || data < start -> info){
        tmp -> link = start;
        start = tmp;
        return start;

    } else{
        ptr = start;
        while(ptr->link != NULL && ptr->link->info < data)
                ptr = ptr -> link;
            tmp -> link = ptr -> link;
            ptr -> link = tmp;

        return start;
    }
}
// main logic of this code
void merge(node *s1, node *s2){

    node *s3 = NULL;

    while(s1 != NULL && s2!= NULL){

        if(s1->info < s2->info){
            s3 = insert(s3, s1->info);
            s1 =s1 -> link;
        }

        else if(s1 -> info > s2 -> info){

            s3 = insert(s3, s2 -> info);
            s2 = s2 -> link;

        }
        else if(s1 -> info == s2 -> info){
            s3 = insert(s3, s2 -> info);
            s1 = s1 -> link;
            s2 = s2 -> link;
        }
    }
    while(s1 != NULL){
        s3 = insert(s3, s1->info);
        s1 =s1 -> link;
    }

    while(s2 != NULL){
        s3 = insert(s3, s2 -> info);
        s2 = s2 -> link;
    }
    printf("Merged list is : ");

    display(s3);
}



int main(){
    node *start1 = NULL, *start2 = NULL;

    start1 = create_list(start1);
    start2 = create_list(start2);

    printf("List 1 is : ");
    display(start1);

    printf("List 2 is : ");
    display(start2);

    merge(start1, start2);

    return 0;
}