#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define List_Size 100/*����ռ�Ĵ�С*/


typedef struct{
	int elem[List_Size]; /*�洢�ռ�*/
	int len;      /*ʵ�ʳ���*/
}SqListStatic;//˳���̬����ķ���������ͨ������ǿ������STL:vector��

typedef struct{
	int *elem;       /*˳���Ĵ洢�ռ�*/
	int len;            /*ʵ�ʳ���*/
	int ListSize; /*��ǰ����Ŀռ��С*/
} SqlistDyn;

int g1=0, g2=0, g3=0;


int main(int argc, char *argv[])
{
	static int s1=0,s2,s4,s3=0;
	const char *pc="12345";
	int v1=0,v2=0,*q=&v2,v3,*p=&v3,v4,v5, *r,*q11=&v2;
	int Sqlist1[100],*s=&Sqlist1,*u=Sqlist1,*v=&Sqlist1[0];//˳���̬����ķ���һ
	int Sqlist2[List_Size];//˳���̬����ķ���
	SqListStatic Sqlist3;
	SqlistDyn Sqlist4;
	int v6;
	//int v7;

	//for (v1=1;v1<=100;v1++)
	//	Sqlist1[v1-1]=v1;

	printf("\n=====���*p��p��&p�Ĺ��������趨��int v3,*p=&v3;======\n");
	printf("�ֲ�����v3���ڴ��ַΪ��0x%08x;\t�ֲ�����v3=0x%08x;\n",&v3,v3);
	printf("*p=0x%08x;\tp=0x%08x;\t&p=0x%08x\n\n",*p,p,&p);

	printf("\n=====���*q��q��&q�Ĺ��������趨��int v2=0,*q=&v2;======\n");
	printf("�ֲ�����v2���ڴ��ַΪ��0x%08x;\t�ֲ�����v2=0x%08x;\n",&v2,v2);
	printf("*q=0x%08x;\tq=0x%08x;\t&q=0x%08x\n\n",*q,q,&q);
	q =(int*) malloc(40);
	printf("ִ��'q =(int*) malloc(40);'�󣺾ֲ�����q���ڴ��ַ��ȡֵ��Ϊ��\n");
	printf("*q=0x%08x;\tq=0x%08x;\t&q=0x%08x\n\n",*q,q,&q);

	q11 =(int*) malloc(40);
	printf("ִ��'q11 =(int*) malloc(40);'�󣺾ֲ�����q11���ڴ��ַ��ȡֵ��Ϊ��\n");
	printf("*q11=0x%08x;\tq11=0x%08x;\t&q11=0x%08x\n\n",*q11,q11,&q11);

	printf("\n=====���*s��s��&s�Ĺ��������趨��int Sqlist1[100],*s=&Sqlist1,*u=Sqlist1,*v=&Sqlist1[0];====\n");
	printf("�ֲ�����Sqlist1���ڴ��ַΪ��0x%08x;\t�ֲ�����Sqlist1=0x%08x\n;",&Sqlist1,Sqlist1);
	printf("*s=0x%08x;\ts=0x%08x;\t&s=0x%08x\n\n",*s,s,&s);
	printf("*u=0x%08x;\tu=0x%08x;\t&u=0x%08x\n\n",*u,u,&u);
	printf("*v=0x%08x;\tv=0x%08x;\t&v=0x%08x\n\n",*v,v,&v);

	printf("\n====ִ��'r=Sqlist1;'ǰ�󣺾ֲ�����r���ڴ��ַ��ȡֵ========\n");
	printf("�ֲ�����r���ڴ��ַΪ��0x%08x;\t�ֲ�����r=0x%08x\n",&r,r);
	r=Sqlist1;
	printf("\n             ===��\n");
	printf("�ֲ�����r���ڴ��ַΪ��0x%08x;\t�ֲ�����r=0x%08x\n",&r,r);

	printf("\n\n====��ӡ���ֲ��������ڴ��ַ��ȡֵ====\n");
	printf("�ֲ�����v1���ڴ��ַΪ��0x%08x;\t�ֲ�����v1=0x%08x;\n",&v1,v1);
	printf("�ֲ�����v2���ڴ��ַΪ��0x%08x;\t�ֲ�����v2=0x%08x;\n",&v2,v2);
	printf("�ֲ�����q���ڴ��ַΪ��0x%08x;\t�ֲ�����q=0x%08x;\n",&q,q);
	printf("�ֲ�����v3���ڴ��ַΪ��0x%08x;\t�ֲ�����v3=0x%08x;\n",&v3,v3);
	printf("�ֲ�����p���ڴ��ַΪ��0x%08x;\t�ֲ�����p=0x%08x;\n",&p,p);
	printf("�ֲ�����v4���ڴ��ַΪ��0x%08x;\t�ֲ�����v4=0x%08x;\n",&v4,v4);
	printf("�ֲ�����v5���ڴ��ַΪ��0x%08x;\t�ֲ�����v5=0x%08x;\n",&v5,v5);
	printf("�ֲ�����r���ڴ��ַΪ��0x%08x;\t�ֲ�����r=0x%08x;\n",&r,r);
	printf("�ֲ�����s���ڴ��ַΪ��0x%08x;\t�ֲ�����s=0x%08x;\n",&s,s);
	printf("�ֲ�����u���ڴ��ַΪ��0x%08x;\t�ֲ�����u=0x%08x;\n",&u,u);
	printf("�ֲ�����v���ڴ��ַΪ��0x%08x;\t�ֲ�����v=0x%08x;\n",&v,v);
	printf("�ֲ�����pc���ڴ��ַΪ��0x%08x;\t�ֲ�����pc=%s;\n",&pc,pc);
	printf("�ֲ�����Sqlist1���ڴ��ַΪ��0x%08x;\t�ֲ�����Sqlist1=0x%08x;\n",&Sqlist1,Sqlist1);
	printf("�ֲ�����Sqlist2���ڴ��ַΪ��0x%08x;\t�ֲ�����Sqlist2=0x%08x;\n",&Sqlist2,Sqlist2);
	printf("�ֲ�����Sqlist3���ڴ��ַΪ��0x%08x;\t�ֲ�����Sqlist3=0x%08x;\n",&Sqlist3,Sqlist3);
	printf("�ֲ�����Sqlist4���ڴ��ַΪ��0x%08x;\t�ֲ�����Sqlist4=0x%08x;\n",&Sqlist4,Sqlist4);
	printf("�ֲ�����v6���ڴ��ַΪ��0x%08x;\t�ֲ�����v6=0x%08x;\n",&v6,v6);
	//printf("�ֲ�����v7���ڴ��ַΪ��0x%08x;\t�ֲ�����v7=0x%08x;\n",&v7,v7);


	printf("\n\n====InitSqList�����Ĵ���������ڴ��ַ��ȡֵ====\n");
	printf("�ֲ�����Sqlist4���ڴ��ַΪ��0x%08x;\t�ֲ�����Sqlist4=0x%08x;\n",&Sqlist4,Sqlist4);
	InitSqList(&Sqlist4);
	printf("ִ��'InitSqList(&Sqlist4);'�󣺾ֲ�����Sqlist4���ڴ��ַ��ȡֵ��Ϊ��\n");
	printf("�ֲ�����Sqlist4���ڴ��ַΪ��0x%08x;\t�ֲ�����Sqlist4=0x%08x;\n",&Sqlist4,Sqlist4);


	printf("\n\n====��ӡ��ȫ�ֱ���(�ѳ�ʼ��)���ڴ��ַ������s========\n");
	printf("ȫ�ֱ���g1���ڴ��ַΪ��0x%08x;\tg1=0x%08x\n",&g1,g1);//��ӡ��ȫ�ֱ������ڴ��ַ
	printf("ȫ�ֱ���g2���ڴ��ַΪ��0x%08x;\tg2=0x%08x\n",&g2,g2);//��ӡ��ȫ�ֱ������ڴ��ַ
	printf("ȫ�ֱ���g3���ڴ��ַΪ��0x%08x;\tg3=0x%08x\n",&g3,g3);//��ӡ��ȫ�ֱ������ڴ��ַ


	printf("\n\n====��ӡ����̬�������ڴ��ַ������s1,s3�ѳ�ʼ��======\n");
	printf("��̬����s1���ڴ��ַΪ��0x%08x;\ts1=0x%08x\n",&s1,s1);
	printf("��̬����s3���ڴ��ַΪ��0x%08x;\ts3=0x%08x\n",&s3,s3);
	printf("��̬����s2���ڴ��ַΪ��0x%08x;\ts2=0x%08x\n",&s2,s2);
	printf("��̬����s4���ڴ��ַΪ��0x%08x;\ts4=0x%08x\n",&s4,s4);



	printf("\n\n====add�����Ĵ���������ڴ��ַ��ȡֵ====\n");
	printf("�ֲ�����v1���ڴ��ַΪ��0x%08x;\t�ֲ�����v1=0x%08x;\n",&v1,v1);
	printf("�ֲ�����v2���ڴ��ַΪ��0x%08x;\t�ֲ�����v2=0x%08x;\n",&v2,v2);
	v4=add(v1,v2);



	printf("\n\n====��ӡ�����ʼ����main��ַ=====\n");
	printf("main��������ڵ�ַΪ: 0x%08x\n\n", main);
	printf("\n\n====��ӡmain�����Ĳ�����ַ=====\n");
	printf("argc���ڴ��ַΪ��0x%08x;\targc: 0x%08x\n\n",&argc,argc);
	printf("argv���ڴ��ַΪ��0x%08x;\targv=0x%08x\n\n",&argv,argv);
	printf("argv[0]���ڴ��ַΪ��0x%08x;\t0x%s\n\n",&argv[0],argv[0]);
	printf("argv[1]���ڴ��ַΪ��0x%08x;\t0x%08x\n\n",&argv[1],argv[1]);
	printf("argv[2]���ڴ��ַΪ��0x%08x;\t0x%08x\n\n",&argv[2],argv[2]);



	printf("\n\n====��ӡ�Ӻ�����ʼ��ַ========\n");
	printf("InitSqList��������ڵ�ַΪ: 0x%08x\n\n",(int)(const void*)InitSqList);
	printf("add��������ڵ�ַΪ: 0x%08x\n\n",(int)(const void*)add);

	system("pause");
	return 1;
}


int InitSqList(SqlistDyn *L)//����һ���յ�˳���L
{
	L->elem=(int *) malloc(List_Size *sizeof(int));
	if (L->elem==NULL)
		exit(EXIT_FAILURE);
	L->len=0;
	L->ListSize =List_Size;
	printf("InitSqList����������....\n");
	printf("�۲��Ӻ��������������a,b��ջ��ַ\n");
	printf("InitSqList������malloc����Ķѵ�ַΪ��0x%08x\n;",L->elem);
	printf("InitSqList������ָ�����L���ڴ��ַΪ��0x%08x;\t�ֲ�����L=0x%08x\n;",&L,L);
	return 1;
}

int add(int a, int b)
{
    int a1,a2;
    printf("0x%08x\t0x%08x\n",&a1,&a2);
	printf("add����������....\n");
	printf("�۲��Ӻ��������������a,b��ջ��ַ\n");
	printf("add�����д���Ĳ���a���ڴ��ַΪ��0x%08x;\t�ֲ�����a=0x%08x\n;",&a,a);
	printf("add�����д���Ĳ���b���ڴ��ַΪ��0x%08x;\t�ֲ�����b=0x%08x\n;",&b,b);
	return (a+b);

}
