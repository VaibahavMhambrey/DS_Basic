#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int info;
    struct node *next;
};
struct node *create_list(struct node *start);
void display(struct node *start);
struct node *addtoempty(struct node *start, int data);
struct node *addatend(struct node *start, int data);
struct node *addatbeg(struct node *start, int data);
struct node *addafter(struct node *start, int data, int item);
struct node *addbefore(struct node *start, int data, int item);
struct node *del(struct node *start, int data);
struct node *reverse(struct node *start);
int main()
{

    struct node *start = NULL;
    int choice, data, item;
    while (1)
    {

        printf("1.Create List\n");
        printf("2.Display\n");
        printf("3.Add to empty list\n");
        printf("4.Add at beginning\n");
        printf("5.Addat end\n\n");
        printf("6.Add after\n\n");
        printf("7.Add before\n\n");
        printf("8.Delete\n");
        printf("9.Reverse\n");
        printf("10.Quit\n\n");
        printf("Enter your choice : ");
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
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            start = addtoempty(start, data);
            break;
        case 4:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            start = addatbeg(start, data);
            break;
        case 5:

            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            start = addatend(start, data);
            break;

        case 6:

            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the element after which to be inserted : ");
            scanf("%d", &item);
            start = addafter(start, data, item);
            break;
        case 7:
            printf("Enter the element to be inserted : ");
            scanf("%d", &data);
            printf("Enter the element before which to be inserted : ");
            scanf("%d", &item);
            start = addbefore(start, data, item);
            break;
        case 8:

            printf("Enter the element to be deleted: ");
            scanf("%d", &data);
            start = del(start, data);
            break;

        case 9:

            start = reverse(start);
            break;
        case 10:
            exit(1);

        default:

            printf("Wrong choice\n");
        }
    }
    return 0;
}

struct node *create_list(struct node *start)
{

    int i, n, data;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);
    start = NULL;
    if (n == 0)
        return start;
    printf("Enter the element to be inserted : ");
    scanf("%d", &data);
    start = addtoempty(start, data);
    for (i = 2; i <= n; i++)
    {
        printf("Enter the element to be inserted : ");
        scanf("%d", &data);
        start = addatend(start, data);
    }
    return start;
}
void display(struct node *start)
{
    struct node *p;
    if (start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    p = start;
    printf("List is:\n");
    while (p != NULL)
    {
        printf("% d ", p->info);
        p = p->next;
    }
    printf("\n\n");
}
struct node *addtoempty(struct node *start, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = NULL;
    start = tmp;
    return start;
}

struct node *addatend(struct node *start, int data)
{
    struct node *tmp, *p;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    p = start;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = tmp;
    tmp->next = NULL;
    tmp->prev = p;
    return start;
}

struct node *addatbeg(struct node *start, int data)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = start;
    start->prev = tmp;
    start = tmp;
    return start;
}

struct node *addafter(struct node *start, int data, int item)
{
    struct node *p, *tmp;
    p = start;
    while (p != NULL)
    {
        if (p->info == item)
        {
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->info = data;
            tmp->prev = p;
            tmp->next = p->next;
            if (p->next != NULL)
                p->next->prev = tmp;
            p->next = tmp;
            return start;
        }
        p = p->next;
    }
    printf("Item % d not found in list\n", item);
    return start;
}
struct node *addbefore(struct node *start, int data, int item)
{
    struct node *p, *tmp;
    if (start == NULL)
    {
        printf("List is empty");
        return start;
    }
    if (start->info == item)

        tmp = (struct node *)malloc(sizeof(struct node));
    tmp->info = data;
    tmp->prev = NULL;
    tmp->next = start;
    start->prev = tmp;
    start = tmp;
    return start;
}
struct node *del(struct node *start, int data)
{
    struct node *tmp;
    if (start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    if (start->next == NULL)
    {
        if (start->info == data)
        {
            tmp = start;
            start = NULL;
            free(tmp);
            return start;
        }
        else
        {
            printf("Element %d not found\n", data);
            return start;
        }
    }
    if (start->info == data)
    {
        tmp = start;
        start = start->next;
        start->prev = NULL;
        free(tmp);
        return start;
    }
}
    struct node *reverse(struct node * start)
    {
        struct node *p1, *p2;
        p1 = start;
        p2 = p1->next;
        p1->prev = p2;
        p1->next = NULL;
        while (p2 != NULL)
        {
            p2->prev = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p2->prev;
        }
        start = p1;
        return start;
    }