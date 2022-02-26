#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct stack
{
    int size;
    int top;
    char *arr;
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

void push(struct stack *ptr,char val){
    if(isFull(ptr)){
        printf("stack overflow\n");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

void pop(struct stack *ptr){
    if (isEmpty(ptr))
    {
        printf("stack underflow\n");
    }
    else
    {
        ptr->arr[ptr->top];
        ptr->top--; 
    } 
}

int parenthesisMatch(char *exp){
    struct stack *sp;
    sp->size=strlen(exp);
    sp->top=-1;
    sp->arr=(char*)malloc(sp->size*sizeof(char));

    for (int i = 0; exp[i]!='\0'; i++)
    {
        if (exp[i]=='(')
        {
            push(sp,'(');
        }
        else if(exp[i]==')')
        {
            if (isEmpty(sp))
            {
                return 0;
            }
            pop(sp);
        }
        if (isEmpty(sp))
        {
            return 1;
        }  
    }
    
}


int main(){
    char exp="(34+34)";
    if (parenthesisMatch(exp))
    {
        printf("parenthesis matched\n");
    }
    else
    {
        printf("parenthesis not matching\n");
    }
    return 0;
}
