#include <stdio.h>
#include <stdlib.h>
#define ARRAY_OR_POINTER 0
int main()
{
    //
    int a[10] = {9,8,7,6,5,4,3,2,1,0};
    int *p=NULL;
    printf("a \t is 0x%08x\n",a);
    printf("&a \t is 0x%08x\n",&a);
    printf("a+1 \t is 0x%08x\n",a+1);

    // &a+1 ��������10*4���ֽڵĳ���
    printf("&a+1 \t is 0x%08x\n",&a+1);
    printf("a+3 \t is 0x%08x\n",a+3);
    printf("&a[3] \t is 0x%08x\n",&a[3]);
    //���벻��ͨ����
    //printf("&(a+3) \t is 0x%08x\n",&(a+3));
    printf("&a[2] \t is 0x%08x\n",&a[2]);
    printf("(&a)[3] \t is 0x%08x\n",(&a)[3]);
    printf("(a[3] \t is 0x%08x\n",a[3]);

    printf("ָ�������������\n");
    p=a;
    printf("p \t is 0x%08x\n",p);
    p = a+1;
    printf("p=a+1 \t is 0x%08x\n",p);
    ++p;
    // ��ʱp�Լ�10���ֽڵĳ���
    printf("++p \t is 0x%08x\n",p);

    p=&a+1;
    printf("p \t is 0x%08x\n",p);
    ++p;
    // ��ʱp�Լ�10���ֽڵĳ���
    printf("++p \t is 0x%08x\n",p);
    return 0;
}
