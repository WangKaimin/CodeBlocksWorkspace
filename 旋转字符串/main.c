#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char *(* fun) (char *, int);

// ��򵥵��뷨��k�ε�ѭ������
char *RightShift01(char *str, int k)
{
    int i, len = strlen(str);
    char c;
    while(k--)
    {
        c = str[len-1];
        for(i=len-1;i>=1;i--)
            str[i] = str[i-1];
        str[0] = c;
    }
    return str;
}

// ������k>=len���ж�
char *RightShift02(char *str, int k)
{
    int i, len = strlen(str);
    char c;
    k %= len;
    while(k--)
    {
        c = str[len-1];
        for(i=len-1;i>=1;i--)
            str[i] = str[i-1];
        str[0] = c;
    }
    return str;
}

// ����ԭ��������Ϊabcd1234��Ҫ��任�ɵ���������Ϊ1234abcd����ѭ��������4λ��
// �Ƚ�֮�󣬲��ѿ��������������ε�˳���ǲ���ģ�1234��abcd���ɰ������ο����������塣
// ����Kλ�Ĺ��̾��ǰ�����������ֽ���һ�¡�
// �任�Ĺ���ͨ�����²�����ɣ�
// ��������abcd��abcd1234 �� dcba1234��
// ��������1234��dcba1234 �� dcba4321��
// ȫ������dcba4321 �� 1234abcd��
char *Reverse(char *str, int begin, int end)
{
    int i=0, j=0;
    char c;
    for(i=begin, j=end; i<j; i++,j--)
    {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
    return str;
}

char * RightShift03(char *str, int k)
{
    int i, len = strlen(str);
    char c;
    k %= len;
    Reverse(str, 0, len - k - 1 );
    Reverse(str, len - k, len - 1 );
    Reverse(str, 0, len - 1 );
    return str;
}
int main()
{
    char str[] = "abcdefghijklmnopqrstuvwxyz";
    fun RightShift = RightShift03;
    printf("%s\tsizeof=%d\tk=%d\n", str, sizeof(str), strlen(str));
    (*RightShift)(str,100);
    printf("%s\n", str);
    return 0;
}
