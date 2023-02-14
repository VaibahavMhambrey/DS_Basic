#include <stdio.h>
#include<stdlib.h>
#include <string.h>

struct node
{
    int info;
    struct node *link;
};

//------------------------
struct node *create_list(struct node *start);
struct node *addatbeg(struct node *start, int data);
struct node *addatend(struct node *start, int data);
void display(struct node *start);
void count(struct node *start);
void search(struct node *start, int item);
struct node *del(struct node *start, int data);

int main()
{
    struct node *start = NULL;
    int choice, data;
    while (1)
    {
        printf("Enter your choice\n");
        printf("1.Create list\n");
        printf("2.Display\n");
        printf("3.Count\n");
        printf("4.Search\n");
        printf("5.Delete");
        printf("6.Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            start = create_list(start);
            break;
        case 2:
            display(start);
            break;
        case 3:
            count(start);
            break;
        case 4:
            printf("enter element to be searched");
            scanf("%d", &data);
            search(start, data);
            break;
        case 5:
            del(start,data);
            break;
        case 6:
            exit(1);
        default:
            printf("Wrong choice\n");
        }
    }
    return 0;
}

// creating list
struct node *create_list(struct node *start)
{
    int i, n, data;
    printf("enter no of nodes\n");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
        return start;
    printf("entet elements to be inserted\n");
    scanf("%d", &data);
    start = addatbeg(start, data);
    for (i = 2; i < n; i++)
    {
        printf("enter elements");
        scanf("%d", &data);
        start = addatend(start, data);
    }
    return start;
}

//------------------------
struct node *addatbeg(struct node *start, int data)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    temp->link = start;
    temp = start;
    return temp;
}

//-------------------------
struct node *addatend(struct node *start, int data)
{
    struct node *p, *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->info = data;
    p = start;
    while (p->link != NULL)
        p = p->link;
    p->link = temp;
    temp->link = NULL;
    return start;
}

//-------------------------
void display(struct node *start)
{
    struct node *p;
    if (start == NULL)
    {
        printf("List is Empty\n");
        return;
    }
    p = start;
    printf("List is \n");
    while (p != NULL)
    {
        printf("%d", p->info);
        p = p->link;
    }
    printf("\n\n");
}

//------------------------
void count(struct node *start)
{
    struct node *p;
    int cnt = 0;
    p = start;
    while (p != NULL)
    {
        p = p->link;
        cnt++;
    }
    printf(" number of elements are %d", cnt);
}

//------------------------
void search(struct node *start, int item)
{
    struct node *p = start;
    int pos = 1;
    while (p != NULL)
    {
        if (p->info == item)
        {
            printf("item %d found at postion %d\n", item, pos);
            return;
        }
        p = p->link;
        pos++;
    }
    printf("Item not in list\n");
}

//------------------------
struct node *del(struct node *start, int data)
{
    struct node *tmp, *p;
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    if (start->info == data)
    {
        tmp = start;
        start = start->link;
        free(tmp);
        return start;
    }
    p = start;
    while (p->link != NULL)
    {
        if (p->link->info == data)
        {
            tmp = p->link;
            p->link = tmp->link;
            free(tmp);
            return start;
        }
        p = p->link;
    }
    printf("Element %d not found\n", data);
    return start;
}