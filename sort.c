#include <stdio.h>
#include<string.h>

typedef struct node{
    char title[100];
    int id;
}book;

void sort(book b[],int n){
    int min,i,j;
    book tmp;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(strcmp(b[min].title,b[j].title)>0)
                min=j;
        }
        if(i!=min){
            tmp=b[i];
            b[i]=b[min];
            b[min]=tmp;
        }
    }
}

void display(book *b,int n){
    for(int i=0;i<n;i++){
        printf("title: ");
        printf("%s\n",b[i].title);
        printf("id: ");
        printf("%d\n",b[i].id);
    }
}

int main(){
    book b[50];
    int n=4;
    for(int i=0;i<n;i++){
        printf("enter name\n");
        scanf("%s",b[i].title);
        b[i].id=i+1;
    }
    display(b,n);
    sort(b,n);
    display(b,n);
}