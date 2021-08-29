#include<stdio.h>
struct student
{
    /* data */
    char name[20];
    int age;
};

int main()
{
    int b[100]={[10]=1,[30]=2};//指定初始化数据元素
    printf("%d,%d,%d\n",b[0],b[10],b[30]);
    int i=4;
    switch(i)
    {
        case 1:
            printf("1\n");
            break;
        case 2 ... 8://... 表示省略中间内容，但是有用
            printf("%d\n",i);
            break;
        case 9:
            printf("9\n");
            break;
        default:
            printf("default!\n");
            break;
    }
    struct student stu1={"liuhao",20};//结构体初始化 方式1
    printf("%s:%d\n",stu1.name,stu1.age);
    struct student stu2={//结构体初始化 方式2
        .name="liuhao",
        .age=21
    };
    printf("%s:%d\n",stu2.name,stu2.age);
    //---
    int sum = 0;
    sum=({
        int s = 0;
        for(int i=0;i<10;i++)
        s=s+i;
        goto here;
        s;
    });//语句块，语句表达式的总值总等于最后一个表达式的值
here:
    printf("here:\n");
    printf("sum=%d\n",sum);
    return 0;
}