#include<stdio.h>

// call by value
// passing structure variable as argument

struct point{
    int x;
    int y;
};

void print(struct point p){
    printf("%d %d \n",p.x,p.y);
}

int main(){
    struct point p1={23,12};
    struct point p2={56,67};
    print(p1);
    print(p2);
    return 0;
}