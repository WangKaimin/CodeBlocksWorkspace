#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

//typedef char *(* strcpy)(char *, const char*);

// const 2��
char * strcpy01(char *dest, const char * src)
{
    char *temp = dest;
    // Ŀ�ꡢԭ�ַ����Ƿ�Ϊ��3��
    assert(dest != NULL && src != NULL);
    // 2��
    while((*dest++ = *src++) != '\0')
        ;
    // ����ֵ3��
    return temp;
}
int main()
{
    char str[] = "wangkaimin";
    char *p = NULL;
    p = strcpy01(str,p);
    //p = strcpy01(str,p);
    printf("str=%s\t%s\n",str,p);
    return 0;
}
