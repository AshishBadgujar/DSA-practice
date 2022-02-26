#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};
struct node *f=NULL;
struct node *r=NULL;

void enqueue(int val){
    struct node *n =(struct node*)malloc(sizeof(struct node));
    if(n==NULL){
        printf("queue is full\n");
    }
    else{
        n->data=val;
        n->next=NULL;
        if(f==NULL){
            f=r=n;
        }else{
            r->next=n;
            r=n;
        }
        printf("item added to queue\n");
    }
}

int dequeue(){
    struct node *ptr =(struct node*)malloc(sizeof(struct node));
    int val=-1;
    ptr=f;
    if (r==NULL)
    {
        printf("queue is empty\n");
    }
    else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val; 
}
int main(){
    
    printf("popped value = %d\n",dequeue());
    
}