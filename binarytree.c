#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int info;
    struct node *left;
    struct node *right;
}node;
node *create_node(int data);
void inorder(node *ptr);
void preorder(node *ptr);
int height(node *ptr);
int main(){
    int h;
    node *ptr = create_node(5);
    node *p1 = create_node(2);
    node *p2 = create_node(3);
    node *p3 = create_node(7);
    node *p4 = create_node(8);
    node *p5 = create_node(4);
    
    ptr -> left = p1;
    ptr -> right = p2;
    p1 -> left = p3;
    p1 -> right = p4;
    p4 -> left = p5;
    
    inorder(ptr); printf("\n");
    h = height(ptr);
    printf("%d", h);
    return 0;
}

node *create_node(int data){
    node *p;
    p = (node *)malloc(sizeof(node));
    p->info = data;
    p -> left = NULL;
    p -> right = NULL;
    return p;
}

void inorder(node *ptr){
    if(ptr == NULL)
        return;
    inorder(ptr ->left);
    printf("%d\t", ptr ->info);
    inorder(ptr ->right);
}

void preorder(node *ptr){
    if(ptr != NULL){
        printf("%d\t", ptr->info);
        preorder(ptr ->left);
        preorder(ptr->right);
    }
}

int height(node *ptr){
    int h_left, h_right;
    if(ptr == NULL){
        return 0;
    }
    h_left = height(ptr->left);
    h_right = height(ptr->right);
    if(h_left > h_right)
         return h_left+1;
    else    
        return h_right+1;
    
}