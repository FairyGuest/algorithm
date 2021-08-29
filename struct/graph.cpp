#include<stdio.h>
#include<stdlib.h>
typedef char VertexType;
#define MAX_VEX_NUM 10
#define MAX_VERTEX_NUM 10
#define MAXSIZE 10
typedef struct{
    VertexType vexs[MAX_VEX_NUM];
    int adj[MAXSIZE][MAXSIZE];
    int vexnum,arcnum;
}MGragh;
void CreatMGraph(MGragh &G){
    int i,j,k,w;
    char ch;
    printf("请输入定点数和边数:\n");
    scanf("%d,%d",&(G.vexnum),&(G.arcnum) );
    printf("请输入顶点信息:\n");
    for(i=0;i<G.vexnum;i++){
        scanf("%c",&(G.vexs[i]));
    }
    for(i=0;i<G.vexnum;i++){
        for(j=0;j<G.vexnum;j++){
            G.adj[i][j]=0;
        }
    }
    printf("输入每条边对应的两个顶点的序号:\n");
    for(k=0;k<G.arcnum;k++){
        scanf("%d,%d",&i,&j);
        G.adj[i][j]=1;
    }
}
typedef struct ArcNode{//边节点
    int adjvex;//邻接点域
    struct ArcNode *nextarc; //指向下一个边节点的指针
    }ArcNode;
typedef struct VNode{//表头结点
    VertexType vertex;
    ArcNode *firstarc;
}VNode;
typedef struct{
    VNode adjlist[MAX_VERTEX_NUM];//结构体数组
    int vexnum,arcnum;//图的当前顶点数和弧数
}ALGraph;
void CreateALGraph(ALGraph &G){
    int i,j,k;
    ArcNode *s;
    printf("请输入顶点数和边数:\n");
    scanf("%d,%d",&(G.vexnum),&(G.arcnum));
    printf("请输入顶点信息:\n");
    for(i=0;i<G.vexnum;i++){//建立表头节点数组
        scanf("%c",&(G.adjlist[i].vertex));
        G.adjlist[i].firstarc=NULL;//结构体数组的firstarc域置空
    }
    printf("请输入边的信息:\n");
    for(k=0;k<G.arcnum;k++){
        scanf("%d,%d",&i,&j);
        s=(ArcNode*)malloc(sizeof(ArcNode));
        s->adjvex=j;
        s->nextarc=G.adjlist[i].firstarc;
        G.adjlist[i].firstarc=s;
        //在链表表头插入节点，从后向前建立链表
    }
}
int main()
{

}