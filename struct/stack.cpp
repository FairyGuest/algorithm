#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
#define TRUE 1
#define OK 1
#define FALSE 0
#define OVERFLOW 0
typedef int Status;
typedef struct std_info
{
    /* data */
    long int Num;
    char Name[8];
    char Sex;
    float Score;
}ElemType;
typedef struct
{
    /* data */
    ElemType elem[MAXSIZE];
    int top;
}SeqStack;
void StackInitiate(SeqStack &s){//置空栈
    s.top=-1;
}
Status Empty_SeqStack(SeqStack s){//判断栈是否为空
    if(s.top==-1) return TRUE;
    else return FALSE;
}
Status StackPush(SeqStack &s,ElemType c){//入栈
    if(s.top>=MAXSIZE-1) return OVERFLOW;
    else s.elem[++s.top]=c;
    return OK;
}
Status StackPop(SeqStack &s,ElemType &c){//出栈
    if(Empty_SeqStack(s)) return OVERFLOW;
    else{
        c=s.elem[s.top];
        s.top--;
        return OK;
    }
}
ElemType Top_SeqStack(SeqStack s){//取栈顶元素
    if(Empty_SeqStack(s)) return ;
    else return(s.elem[s.top]);
}
//链式栈，通过指针的方式实现栈
typedef struct{
    ElemType *base;
    ElemType *top;
    int stacksize;
}SqStack;
typedef struct node{
    ElemType data;
    struct node *next;
}StackNode;
void Init_LS(StackNode *top){
    top=NULL;
}
int Empty_LS(StackNode *top){
    return (top==NULL);
}
StackNode *Push_LS(StackNode *top,ElemType x){
    StackNode *p=(StackNode *)malloc(sizeof(StackNode));
    p->data=x;
    p->next=top;//建立连接
    top=p;//置栈顶
    return top;
}
Status Pop_LS(StackNode *top,ElemType &y){
    StackNode *p;
    if(Empty_LS(top)){
        printf("Stack Underflow");
        return OVERFLOW;
    }
    else{
        y=top->data;
        p=top;
        top=top->next;
        free(p);
        return OK;
    }
}
Status GetTop(StackNode *top,ElemType &y){
    if(Empty_LS(top)){
        printf("Stack underflow");
        return OVERFLOW;
    }
    else{
        y=top->data;
        return OK;
    }
}
int main(){
    
}