#include<stdio.h>

// call by adress
//passing pointers to sturctuer as asn argument

struct point{
    int x;
    int y;
};

void print(struct point *ptr){
    printf("%d %d \n",ptr->x,ptr->y);
}

int main(){
    struct point p1={23,12};
    struct point p2={56,67};
    print(&p1);
    print(&p2);
    return 0;
}