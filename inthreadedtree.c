#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node{
    struct node *left;
    int info;
    bool lthread;
    bool rthread;
    struct node *right;
}node;

void inorder(node *root);
node *in_succ(node *ptr);
node *inpre(node *ptr);
node *insert(node *root, int ikey);
node *search(node *ptr, int skey);
node *del(node *root, int dkey);
node *case_a(node *root, node *par, node*ptr);
node *case_b(node *root, node *par, node*ptr);
node *case_c(node *root, node *par, node*ptr);
int main(){
    int choice, key, n, i;
    node *root = NULL, *ptr;

    int arr[] = {8,7,6,5,9,1,3,2,4};
    for(i=0; i<9; i++){
        root = insert(root, arr[i]);
    }
    while(1){
        printf("\n");
        printf("1:Insert\n");
        printf("2:Delete\n");
        printf("3:Inorder\n");
        printf("4:Searching\n");
        printf("5:Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter node:\n");
                scanf("%d", &key);
                root = insert(root, key);
                break;
            case 2:
                printf("Enter the key you want to delete\n");
                scanf("%d", &key);
                root = del(root, key);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                printf("Enter a key to search:\n");
                scanf("%d", &key);
                ptr = search(root, key);
                if(ptr == NULL){
                    printf("Key not present\n");
                }
                else{
                    printf("Key present\n");
                }
                break;
            case 5:
                exit(1);
                break;
            default:
                printf("Invalid choice!");
        }
    }

    return 0;
}

node *insert(node *root, int ikey){

    node *tmp, *par, *ptr;
    int found = 0;
    ptr = root, par = NULL;
    while(ptr != NULL)
    {
        if(ikey == ptr -> info){
            found = 1;
            break;
        }
        par = ptr;
        if(ikey < ptr -> info){
            if(ptr -> lthread == false)
                ptr = ptr -> left;
            else
                break;
        }
        else{
            if(ptr -> rthread == false)
                ptr = ptr -> right;
            else    
                break;
        }
    }
    if(found){
        printf("Duplicate key!\n");
    }
    else{
        tmp = (node *)malloc(sizeof(node));
        tmp ->info = ikey;
        tmp ->lthread = true;
        tmp -> rthread = true;
        if(par == NULL){
            root = tmp;
            tmp -> left = NULL;
            tmp -> right = NULL;
        }
        else if(ikey < par -> info){
            tmp -> left = par -> left;
            tmp -> right = par;
            par -> lthread = false;
            par -> left = tmp;
        }
        else{
            tmp -> right = par -> right;
            tmp -> left = par;
            par -> rthread = false;
            par -> right = tmp;
        }

    }
    return root;
}

node *search(node *ptr, int skey){
    if(ptr == NULL){
        printf("key not found\n");
        return NULL;
    }
    else if(skey < ptr -> info)
        return search(ptr ->left, skey);
    else if(skey > ptr -> info)
        return search(ptr -> right, skey);
    else    
        return ptr;
}

void inorder(node *root){
    node *ptr;

    if(root == NULL){
        printf("Tree is empty!");
        return;
    }
    ptr = root;
    while(ptr -> lthread == false)
        ptr = ptr -> left;

    while(ptr != NULL){
        printf("%d ", ptr -> info);
        ptr = in_succ(ptr);
    }
}

node *in_succ(node *ptr){
    if(ptr -> rthread == true)
        return ptr -> right;
    else{  
        ptr = ptr -> right;
        while(ptr -> lthread == false)
            ptr = ptr -> left;
        return ptr;
    }
}

node *inpre(node *ptr)
{
    if (ptr->lthread == true)
        return ptr->left;
    else
    {
        ptr = ptr->left;
        while (ptr->rthread == false)
            ptr = ptr->right;
        return ptr;
    }
}

node *case_a(node *root, node *par, node*ptr){
    if(par == NULL)
        root = NULL;
    else if(ptr == par -> left){
        par -> lthread = true;
        par -> left = ptr -> left;
    }
    else{
        par -> rthread = true;
        par -> right = ptr -> right;
    }
    free(ptr);
    return root;
}

node *case_b(node *root, node *par, node *ptr){
    node *child, *s,*p;

    if(ptr -> lthread == false)
        child = ptr -> left;
    else    
        child = ptr -> right;
    if(par == NULL)
        root = child;
    else if(ptr == par -> left)
        par -> left = child;
    else    
        par -> right = child;

    s = in_succ(ptr);
    p = inpre(ptr);

    if(ptr -> lthread == false)
        p -> right = s;
    else{
        if(ptr -> rthread == false)
            s -> left = p;
    }
    free(ptr);
    return root;
}

node *case_c(node *root, node *par, node *ptr){
    node *succ, *parsucc;
    parsucc = ptr;
    succ = ptr -> right;

    while(succ -> left != NULL)
    {
        parsucc = succ;
        succ = succ -> left;
    }
    ptr -> info = succ -> info;

    if(succ -> lthread == true && succ -> rthread == true)
        root = case_a(root, par, ptr);
    else
        root = case_b(root, par, ptr);
    return root;
}

node *del(node *root, int dkey){
    int f = 1;
    node *ptr, *par;
    ptr = root;
    par = NULL;
    while (ptr != NULL)
    {
        if (ptr->info == dkey)
        {
            f = 0;
            break;
        }
        par = ptr;
        if (dkey < ptr->info)
        {
            if (ptr->lthread == false)
                ptr = ptr->left;
            else
                break;
        }
        else
        {
            if (ptr->rthread == false)
                ptr = ptr->right;
            else
                break;
        }
    }
    if (f == 1)
        printf("Key not found\n");
    else
    {
        if (ptr->lthread == false && ptr->rthread == false)
            root = case_c(root, par, ptr);
        else if (ptr->right == false || ptr->lthread == false)
            root = case_b(root, par, ptr);
        else
            root = case_a(root, par, ptr);
    }
    return root;
}