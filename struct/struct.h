#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
#define TRUE 1
#define OK 1
#define FALSE 0
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