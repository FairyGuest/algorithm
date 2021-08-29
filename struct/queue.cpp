#include <stdio.h>
#include <stdlib.h>
#include "struct.h"
typedef struct{
    ElemType elem[MAXSIZE];
    int rear,front;
}SeQueue;
void Init_SeQueue(SeQueue &sq){//置空队
    sq.front=sq.rear=0;
}
Status Empty_Sequeue(SeQueue sq){//判断队空
    if(sq.front==sq.rear)
    return TRUE;
    else return FALSE;
}
Status In_SeQueue(SeQueue &sq,ElemType x){
    if((sq.rear+1)%MAXSIZE==sq.front){
        printf("队满");
        return OVERFLOW;
    }
    else {
        sq.elem[sq.rear]=x;
        sq.rear=(sq.rear+1)%MAXSIZE;
        return OK;
    }
}
Status Out_SeQueue(SeQueue &sq,ElemType &y){
    if(Empty_Sequeue(sq)){
        printf("空");
        return OVERFLOW;
    }
    else{
        y=sq.elem[sq.front];
        sq.front=(sq.front+1)%MAXSIZE;
        return OK;
    }
}