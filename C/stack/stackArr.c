#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(struct stack *ptr){
    if(ptr->top== -1){
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr,int val){
    if(isFull(ptr)){
        printf("stack overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(struct stack *ptr){
    if (isEmpty(ptr))
    {
        printf("stack underflow\n");
        return 0;
    }
    else
    {
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    } 
}

int peek(struct stack *ptr,int i){
    if(ptr->top-i+1 < 0){
        printf("position invalid\n");
        return -1;
    }
    else{
        return ptr->arr[ptr->top-i+1];
    }
}

int main(){
    int val=4;
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=8;
    s->top=-1;
    s->arr=(int *)malloc(s->size * sizeof(int));
    printf("is full: %d \n",isFull(s));
    printf("is empty:%d \n",isEmpty(s));
    // 1 -true ,0-false
    // printf("Enter number in your stack :");
    // scanf("%d",val);
    // printf("%d",val);
    push(s,val);
    push(s,2);
    push(s,45);
    push(s,67);
    
    printf("is full: %d \n",isFull(s));
    printf("is empty:%d \n",isEmpty(s));

    for (int i = 1; i < s->size; i++)
    {
        printf("%d\n",peek(s,i));
    }
    printf("poped value : %d\n",pop(s));
    for (int i = 1; i < s->size; i++)
    {
        printf("%d\n",peek(s,i));
    }
    
}
