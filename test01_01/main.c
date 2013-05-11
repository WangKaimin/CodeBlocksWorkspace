/*
* ���ȣ����ж�ȡָ���ļ��е����ݣ������н����󱣴���˳����С�
* ���У��ļ���ÿ�����ݸ�ʽΪ��ѧ��,����,���䡱�����硰SA10225048,����,24����
*
* ����ʾ������˳���ṹʱ��˳�����ÿ����Ԫ�ذ���������Ϣ��ѧ�ţ������������䣻
* ���õ�����ṹʱ����������ÿ���������������������Ϣ��ѧ�ţ������������䡣��
*
* �ٸ��ݼ������������ز��������ң�ɾ���Ͳ��룩��
* ���磬����������Ϊ��P3�������ʾ��ӡ����3�����Ϣ
* ��ע�⣺����˳���ṹʱ����3�����ݶ�Ӧ�±�Ϊ2�ı�Ԫ�أ�
* ���õ�����ṹʱ����3�����ݶ�Ӧ�����е�3��������Ϣ������
*
* ����������Ϊ��D3�������ʾɾ����3����Ԫ�أ�
*
* ����������Ϊ��I3,SA10225038,����,24����
* ���ʾ�ڵ�3��ǰ����һ��ѧ������Ϣ��SA10225038,����,24����
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME    20
#define MAX_ID      12
#define FIRST_MALLOC    100
#define SECOND_REALLOC  50

struct Node
{
    char id[MAX_ID];
    char name[MAX_NAME];
    unsigned int age;
};

typedef struct Node *pstu;

struct Node1 {
    pstu stu;
    unsigned count; // ѧ������
    unsigned cap;   // �ѷ����С
} stus;

void init();
pstu str2stu(char*);
void stucpy(pstu, pstu);
pstu alloc(pstu);
void firstmalloc();
void secondrealloc();
int ins(unsigned, char*);
int del(unsigned);
int print(unsigned);
void freeNode(pstu);
void destroyNode();

int main()
{
    char comm[50];
    int pos;
    init();

    while(scanf("%s",comm) != EOF)
    {
        pos = 0;
        sscanf(comm+1,"%d",&pos);
        if(comm[0] == '0')
        {
            printf("exit");
            break;
        }
        if(pos == 0)
            continue;
        switch(comm[0])
        {
        case 'P':
            print(pos);
            fflush(stdin);
            break;
        case 'D':
            del(pos);
            fflush(stdin);
            break;
        case 'I':
            ins(pos, comm+3);
            fflush(stdin);
            break;
        default :
            break;
        }
    }
    destroyNode();
    return 0;
}

void init()
{
    int i=0;
    char stu[50];
    if(stus.cap == 0)
        firstmalloc();
    printf("Initting, insert from Lab1test.DAT\n");
    if(freopen("Lab1test.DAT","r",stdin) != NULL)
    {

        while(scanf("%s",stu) != EOF)
        {
            ins(++i,stu);
        }
        //fclose(stdin);
        freopen("CON","r",stdin);
        //printf("Successfully insert %d data.\n",stus.count);
    }
    else
    {
        freopen("CON","r",stdin);
        printf("��ʼ�ļ�Lab1test.DAT�����ڣ�������ֶ�����\n");
    }

}

pstu str2stu(char stu[])
{
    int i;
    pstu p=(pstu)malloc(sizeof(struct Node));
    if(p == NULL)
        exit(1);
    for(i=0; stu[i] != '\0'; i++)
        if(stu[i] == ',')
            stu[i] = ' ';
    //printf("stu=%s\n",stu);
    sscanf(stu,"%s%*c%s%*c%d",p->id,p->name,&p->age);
    //printf("id=%s name=%s age=%d\n",p->id,p->name,p->age);
    return p;
}

void stucpy(pstu src, pstu dst)
{
    strcpy(src->id, dst->id);
    strcpy(src->name, dst->name);
    src->age = dst->age;
}


void firstmalloc()
{
    stus.stu = (pstu)malloc(sizeof(struct Node)*FIRST_MALLOC);
    if(stus.stu == NULL)
        exit(1);
    stus.cap = FIRST_MALLOC;
    stus.count = 0;
    //printf("FirstMalloc();\n");
}

void secondrealloc()
{
    stus.stu = (pstu)realloc(stus.stu,sizeof(struct Node)*(SECOND_REALLOC+stus.cap));
    if(stus.stu == NULL)
    {
        exit(0);
    }
    stus.cap += SECOND_REALLOC;
    //printf("SecondRealloc();\n");
}

int ins(unsigned pos, char stu[])
{
    int i;
    pstu to_add;
    if(pos<1 || pos > stus.count+1)
        return 1;
    if(stus.count == stus.cap)
        secondrealloc();
    to_add = str2stu(stu);

    for(i=stus.count;i>=pos;i--)
    {
        stucpy(&(stus.stu[i]), &(stus.stu[i-1]));
    }

    stucpy(&(stus.stu[i]), to_add);
    stus.count++;
    printf("Successfully insert %s\n",stu);
    freeNode(to_add);
    return 0;
}
int del(unsigned pos)
{
    int i;
    if(pos <1 || pos > stus.count)
        return 1;
    printf("Successfully delete Info %s %s %d\n",
           stus.stu[pos-1].id,stus.stu[pos-1].name,stus.stu[pos-1].age);
    for(i=pos-1; i<stus.count-1; i++)
    {
        stucpy(&(stus.stu[i]), &(stus.stu[i+1]));
    }
    stus.count--;
    return 0;
}
int print(unsigned pos)
{
    pstu now;
    if(pos <1 || pos > stus.count)
        return 1;
    now = &stus.stu[pos-1];
    printf("%s %s %d\n",now->id,now->name,now->age);
    return 0;
}
void freeNode(pstu now)
{
    free(now);
}
void destroyNode()
{
    free(stus.stu);
}
