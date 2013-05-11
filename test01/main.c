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

#define MAX_NAME    20
#define MAX_ID      11

struct Node
{
    char *id;
    char *name;
    unsigned int age;
    struct Node *next;
};

typedef struct Node *pstu;
pstu head;
unsigned count;

void init();
pstu str2stu(char*);
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
        sscanf(comm+1,"%d",&pos);
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
        if(comm[0] == '0')
        {
            printf("exit");
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
//    head = (pstu)malloc(sizeof(struct Node));
//    if(head == NULL)
//        exit(1);
//    head->next = NULL;
    head = NULL;
    count = 0;
    printf("Initting, insert from Lab1test.DAT\n");

    if(freopen("Lab1test.DAT","r",stdin) != NULL)
    {

        while(scanf("%s",stu) != EOF)
        {
            ins(++i,stu);
        }
        //fclose(stdin);
        freopen("CON","r",stdin);
        printf("Successfully insert %d data.\n",count);
    }
    else
        printf("��ʼ�ļ�Lab1test.DAT�����ڣ�������ֶ�����\n");
}

pstu str2stu(char *stu)
{
    int i;
    pstu p=(pstu)malloc(sizeof(struct Node));
    if(p == NULL)
        exit(1);
    p->id = (char*)malloc(sizeof(char)*MAX_ID);
    p->name = (char*)malloc(sizeof(char)*MAX_NAME);
    if(p->id == NULL || p->name == NULL)
        exit(1);
    for(i=0; stu[i] != '\0'; i++)
        if(stu[i] == ',')
            stu[i] = ' ';
    //printf("%s\n",stu);
    sscanf(stu,"%s%*c%s%*c%d",p->id,p->name,&p->age);
    //printf("%s %s %d\n",p->id,p->name,p->age);
    return p;
}

int ins(unsigned pos, char *stu)
{
    int i;
    pstu now, to_add;
    pstu dump = (pstu)malloc(sizeof(struct Node));
    if(dump == NULL)
        exit(1);
    dump->next = head;
    now = dump;
    if(pos > count+1)
        return 1;
    to_add = str2stu(stu);
    for(i=1; i<pos; i++)
    {
        now = now->next;
    }
    to_add->next = now->next;
    now->next = to_add;
    count++;
    printf("Successfully insert %s\n",stu);
    head = dump->next;
    free(dump);
    return 0;
}
int del(unsigned pos)
{
    int i;
    pstu dump = (pstu)malloc(sizeof(struct Node));
    if(dump == NULL)
        exit(1);
    dump->next = head;
    pstu pre=dump, now;
    if(pos <=0 || pos > count)
        return 1;
    for(i=1; i<pos; i++)
    {
        pre = pre->next;
    }
    now = pre->next;
    pre->next = now->next;
    printf("Successfully delete Info %s %s %d\n",now->id,now->name,now->age);
    freeNode(now);
    count--;
    head = dump->next;
    free(dump);
    return 0;
}
int print(unsigned pos)
{
    int i;
    pstu dump = (pstu)malloc(sizeof(struct Node));
    if(dump == NULL)
        exit(1);
    dump->next = head;
    pstu now = dump;
    if(pos <=0 || pos > count)
        return 1;
    for(i=1; i<=pos; i++)
    {
        now = now->next;
    }
    printf("%s %s %d\n",now->id,now->name,now->age);
    free(dump);
    return 0;
}
void freeNode(pstu now)
{
    free(now->id);
    free(now->name);
    free(now);
}
void destroyNode()
{
    pstu now;
    while(head->next != NULL)
    {
        now = head->next;
        head->next = now->next;
        freeNode(now);
    }
    free(head);
}
