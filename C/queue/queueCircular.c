#include<stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q){
   if((q->r+1)% q->size == q->f){
       return 1;
   } 
   else
   {
       return 0;
   }
}

int isEmpty(struct queue *q){
    if(q->f==q->r){
        return 1;
    }
    else
   {
       return 0;
   }
}

void enqueue(struct queue *q,int val){
    if(isFull(q)){
        printf("queue overflow\n");
    }
    else
    {
        q->r=(q->r+1)%q->size;   //incrementation of r
        q->arr[q->r]=val;
        printf("item added to queue\n");
    }
}

int dequeue(struct queue *q){
    if(isEmpty(q)){
        printf("queue underflow\n");
        return -1;
    }
    else{
        q->f=(q->f+1)%q->size;     //incrematation of f
        int x=q->arr[q->f];
        return x;
    }
}


int main(){
    struct queue q;
    q.size=4;
    q.f=q.r=0;
    q.arr=(int*)malloc(q.size*sizeof(int));
    printf("isFull=%d\n",isFull(&q));
    printf("isEmpty=%d\n",isEmpty(&q));
    enqueue(&q,4);
    enqueue(&q,3);
    enqueue(&q,2);
    enqueue(&q,28);
    printf("popped element =%d\n",dequeue(&q));
    enqueue(&q,5);
    enqueue(&q,6);

    return 0;
}