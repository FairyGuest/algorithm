#include<stdio.h>
#include<stdlib.h>
#define OK 1
#define OVERFLOW 0
#define ERROR 0
typedef int Status;
typedef struct std_info
{
    /* data */
    long int Num;
    char Name[8];
    char Sex;
    float Score;
}ElemType;
#define LIST_INIT_SIZE 100 //存储空间初始分配量
#define LISTTINCREMENT 10//存储空间分配增量
typedef struct {
    ElemType *elem;//存储空间分配基址
    int length;//当前长度
    int listsize;//当前分配的存储容量
} SqList;
//初始化，增删改查取
//初始化
Status InitList_Sq(SqList &L){
    L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if(!L.elem)
    exit(OVERFLOW);
    L.length=0;
    L.listsize=LIST_INIT_SIZE;
    return OK;
}
//插入
Status ListInsert_Sq(SqList &L,int i,ElemType e){ //L表示链表，i表示插入位置，e表示插入元素
    ElemType *p;
    if(i<1||i>L.length+1)
    return ERROR;
    if(L.length>=L.listsize){//存储空间已满，分配新的存储空间
        ElemType *newbase=(ElemType *)realloc(L.elem,(L.listsize+LISTTINCREMENT)*sizeof(ElemType));
        if(!newbase)
        return ERROR;
        L.elem=newbase;
        L.listsize+=LISTTINCREMENT;
    }
    ElemType *q=&(L.elem[i-1]);//q为插入位置，下表从0开始计算所以是i-1
    for(p=&(L.elem[L.length-1]);p>=q;--p)//插入位置后的元素全部右移
    *(p+1)=*p;
    *q=e;//插入e
    ++L.length;//长度加1
    return OK;

    }
    //删除
Status ListDelete_Sq(SqList &L,int i,ElemType &e){//在线性表L中删除第i个元素，用e返回其值
    ElemType *p,*q;
    if(i<1||i>L.length){
        return ERROR;
    }
    p=&(L.elem[i-1]);//给p赋值第i个元素
    e=*p;//用e返回
    q=L.elem+L.length-1;//表尾元素的位置
    for(++p;p<=q;++p)//删除位置后的元素位置全部上移
    *(p-1)=*p;
    --L.length;
    return OK;
}
//查找
Status Eisequal(ElemType x,ElemType y){//判断线性表中的元素是否相等
    if(x.Name==y.Name){
        if(x.Num==y.Num){
            if(x.Sex=y.Sex){
                if(x.Score==y.Score){
                    return OK;
                }
            }
        }
    }
    else{
        return ERROR;
    }
}
Status compareplus(ElemType x,ElemType y){//判断元素的大小，判断依据是score
    if(x.Score<=y.Score){
        return OK;
    }else if(x.Score>=y.Score){
        return ERROR;
    }
}
Status compare (ElemType x,ElemType y){
    if(Eisequal(x,y))
    return 1;
    else
    return 0;
}
int LocateElem_Sq(SqList L,ElemType e,Status(*compare)(ElemType,ElemType)){/*Status(*compare)(ElemType,ElemType)表示指向函数的指针
    可以直接通过(*compare)(ElemType,ElemType)来调用*/
    int i;
    ElemType *p;
    i=1;//表示第一个元素的位置
    p=L.elem;//初值为第一个元素的存储位置
    while(i<=L.length&& !(*compare)(*p++,e))
    ++i;
    if(i<=L.length)
    return i;
    else
    return 0;
}
void MergeList_Sq(SqList La,SqList Lb,SqList &Lc){//两个线性表的合并
    ElemType *pa,*pb,*pc,*pa_last,*pb_last;
    pa=La.elem;
    pb=Lb.elem;
    Lc.listsize=Lc.length=La.length+Lb.length;
    pc=Lc.elem=(ElemType *)malloc(Lc.listsize*sizeof(ElemType));
    if(!Lc.elem)
    exit(OVERFLOW);
    pa_last=La.elem+La.length-1;
    pb_last=Lb.elem+Lb.length-1;
    while(pa<=pa_last&&pb<=pb_last){
        if(compareplus(*pa,*pb)==1)
        *pc++=*pa++;
        else
        *pc++=*pb++;
    }
    while(pa<=pa_last) *pc++=*pa++;
    while(pb<=pb_last) *pc++=*pb++;
}
int main(){
    void swap(int x,int y);
    int a=5,b=9;
    swap(a,b);
    printf("a=%d,b=%d",a,b);
}
/*void swap(int x,int y){
    int temp;
    temp=x;
    x=y;
}*/
