#include "struct.h"
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;
typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild,*parent;
}BiTNode_p;
Status visit(ElemType *e){
    printf("%d",e->Num);
    return OK;
}
Status PreOrderTraVerse(BiTree T,Status(*visit)(ElemType)){//通过递归的方式去遍历（前序遍历）
    if(T){
        if(visit(T->data))
        if(PreOrderTraVerse(T->lchild,visit))//遍历左节点
        if(PreOrderTraVerse(T->rchild,visit))//遍历右节点
        return OK;
        return ERROR;
    }

}
void Inorder(BiTNode *bt){//(中序遍历)
    Inorder(bt->lchild);//中序遍历左子树
    printf("%d",bt->data.Num);//访问根节点
    Inorder(bt->rchild);//中序遍历右子树
}
void PostOrder(BiTNode *bt){
    PostOrder(bt->lchild);
    PostOrder(bt->rchild);
    printf("%d",bt->data.Num);
}
BiTree CreateBiTree(BiTree &T){
    char ch;
    scanf("%c",&ch);
    if(ch=='.')
    T=NULL;
    else{
        //if(!(T=(BiTNode *)malloc(sizeof(BiTNode))))
        //return ERROR;
        //T->data=ch;生成根节点，主要是给数据域赋值
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
    return T;
}
/*Status InOrderTraverse(BiTree T,Status(*Visit)(ElemType)){
    stack S;
    BiTree p;
    InitStack(S);
    p=T;
    while(p||StackEmpty(S)){
        if(p){
            Push(S,p);
            p=p->lchild;
        }
        else{
            Pop(S,p);
            if(!visit(p->data));
            return ERROR;;
            p=p->rchild;
        }
    }
    return OK;
}*/
typedef enum PointerTag{Link,Thread};
typedef struct BiThrNode{
    ElemType data;
    struct BiThrNode *lchild,*rchild;
    PointerTag Ltag,Rtag;/*
    在每个节点中增设了两个标志位Ltag和Rtag
    Ltag：0 lchild指向节点的左孩子；1 lchild指向节点的直接前驱节点
    Rtag: 0 rchild指向节点的右孩子；1 rchild指向节点的直接后继节点
    */
}BiThrNode,*BiThrNode,BiThrTree;
Status InOrderTraverse_Thr(BiThrTree T,Status(*visit)(ElemType)){
    BiThrTree p;
    p=T->lchild;
}