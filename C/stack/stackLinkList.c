#include <stdio.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};

void linkListTravesal(struct Node *ptr){
    while(ptr !=NULL){
        printf("Element :%d\n",ptr->data);
        ptr=ptr->next;
    }
}

int isFull(struct Node *top){
    struct Node*p=(struct Node*)malloc(sizeof(struct Node));
    if(p==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct Node *top){
    if(top==NULL){
        return 1;
    }
    else
    {
        return 0;
    }
}

struct Node* push(struct Node*top,int x){
    if(isFull(top)){
        printf("stack overflow");
    }
    else
    {
        struct Node *n=(struct Node *)malloc(sizeof(struct Node));
        n->data=x;
        n->next=top;
        top=n;
        return top;
    }
}
int pop(struct Node**top){
    if (isEmpty(*top))
    {
        printf("stack underflow");
    }
    else
    {
        struct Node *n=*top;
        *top=(*top)->next;
        int x=n->data;
        free(n);
        return x;
    }     
}

int peek(struct Node *top,int pos){
    struct Node *ptr=top;
    for (int i = 0; i < pos-1 && ptr!=NULL; i++)
    {
        ptr=ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    else
    {
        return -1;
    }
}

int stackTop(struct Node *top){
    return top->data;
}

int stackBottom(struct Node *top){
    struct Node *ptr=top;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    return ptr->data;
} 

int main(){
    struct Node *top=NULL;
    top=push(top,78);
    top=push(top,35);
    top=push(top,44);
    top=push(top,45);
    top=push(top,83);
    int element=pop(&top);
    printf("popped element :%d\n",element);
    for (int i = 1; i <= 4; i++)
    {
        printf("value at position %d is:%d\n",i,peek(top,i));
    }
    linkListTravesal(top);
    printf("value at top is:%d\n",stackTop(top));
    printf("value at bottom is:%d\n",stackBottom(top));
    return 0; 
}
