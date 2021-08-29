#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define ERROR 0
#define Status int
typedef struct Lnode{
    int data;
    //char name[8];
    //int score;
    struct Lnode *next;
}LNode,*LinkList;
LinkList CreateList_1(int n){
    LinkList p,H;
    int i;
    H=(LinkList)malloc(sizeof(LNode));
    H->next=NULL;
    for(i=n;i>0;--i){
        p=(LinkList)malloc(sizeof(LNode));
        p->data=i;
        p->next=H->next;
        H->next=p;//头插法建立链表；
    }
    return H;
}
LinkList CreateList_2(int n){//Head是头节点，不会变，r一开始指向头指针，后来会指向链表尾，s是一个临时指针，用完后会指向NULL
    LinkList Head=(LinkList)malloc(sizeof(LNode));
    Head->data=NULL;
    LNode *s,*r=Head;
    int x;
    while(x<n){
        s=(LinkList)malloc(sizeof(LNode));
        s->data=x;
        r->next=s;
        r=s;
        s->next=NULL;
    }
    return Head;
}
int Length_LinkList(LinkList H){
    LNode *p=H;
    int j=0;
    while(p->next){
        p=p->next;
        j++;
    }
    return j;
}
Status GetElem_L(LinkList L,int i,int data){//L是带头结点的链表
    LinkList p;
    p=L->next;
    int j=1;
    while(p&&j<i){
        p=p->next;
        ++j;
    }
    if(!p||j>i)
    return ERROR;
    //data=p->data;
    printf("%d",p->data);
    return OK;
}
Status ChangeList(LinkList L,int i,int data){
    LinkList p;
    p=L->next;
    int j=1;
    while(p&&j<i){
        p=p->next;
        ++j;
    }
    if(!p||j>i)
    return ERROR;
    p->data=data;
    return OK;
}
Status ListInsert_L(LinkList &L,int i,int data){
    LinkList p,s;
    p=L;
    int j=0;
    while(p&&j<i-1){
        p=p->next;
        ++j;
    }
    if(!p||j>i-1)
    return ERROR;
    s=(LinkList)malloc(sizeof(LNode));
    s->data=data;
    s->next=p->next;//此处顺序不可变
    p->next=s;
    return OK;
}
Status ListDelete_L(LinkList &L,int i,int data){
    LinkList p,q;
    p=L;
    int j=0;
    while(p->next&&j<i-1){
        p=p->next;
        ++j;
    }
    if(!(p->next)||j>i-1){
        return ERROR;
    }
    q=p->next;//确定删除的位置
    p->next=q->next;//链表指针越过需要删除的元素
    data=q->data;
    free(q);
    return OK;
}
int Delete_L(LinkList &H,int data){//删除所有值为data的节点，并返回值为data的节点个数
    LNode *p,*q;q=H;int count=0;
    while(q->next){
        p=q->next;
        if(p->data==data){
            q->next=p->next;
            free(p);
            ++count;
        }
        else
        q=p;
    }
    return count;
}
int main(){
    int n=5;
    LinkList H=CreateList_1(n);
    int t;
    int i;
    int data;
    printf("请选择模式\n");
START:    while(1){
    printf("1:获取表的长度\n");
    printf("2:获取对应位置的元素\n");
    printf("3:在对应位置插入元素\n");
    printf("4:删除对应位置的元素\n");
    printf("5:更改对应位置的元素\n");
        scanf("%d",&t);
        switch(t){
            case 1:i=Length_LinkList(H);printf("长度为%d\n",i);break;
            case 2:scanf("%d",&i);GetElem_L(H,i,data);break;
            case 3:scanf("%d,%d",&i,&data);ListInsert_L(H,i,data);printf("插入成功\n");break;
            case 4:scanf("%d",&i);ListDelete_L(H,i,data);printf("删除成功\n");break;
            case 5:scanf("%d,%d",&i,&data);ChangeList(H,i,data);printf("更改成功\n");break;
            default:printf("操作失败，请重试\n");goto START;
        }
        goto START;
    }
}