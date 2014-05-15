/*
004���ڶ�Ԫ�����ҳ���Ϊĳһֵ������·��
��Ŀ������һ�������Ϳö�Ԫ����
�����ĸ���㿪ʼ���·���һֱ��Ҷ���������γ���·����
��ӡ����������������ȵ�����·����
*/
#include "tree.h"
#include <stdio.h>

static void printPath(int path[], int top)
{
    int i=0;
    for(i=0;i<top-1;i++)
        printf("%d ", path[i]);
    printf("%d\n", path[i]);
}

static void helper(BinaryTree *root, int sum, int path[], int top)
{
    path[top] = root->e;
    sum -= path[top];
    top++;
    if(NULL == root->pLeft && NULL == root->pRight)
    {
        if(0 == sum)
            printPath(path, top);
    }
    else
    {
        if(NULL != root->pLeft)
            helper(root->pLeft, sum, path, top);
        if(NULL != root->pRight)
            helper(root->pRight, sum, path, top);
    }
    top--;
    sum += root->e;
}

void printPaths(BinaryTree *root, int sum)
{
    int top=0;
    int path[TREE_DEPTH];
    helper(root, sum, path, top);
}
