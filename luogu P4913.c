#include <stdio.h>
#include <stdlib.h>

#define MAX 1000010

typedef struct
{
    int left;
    int right;
} node;

int max(int a,int b)
{
    if(a>b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int depth=0;
node tree[MAX];

void search(int id,int d)
{
    if(id==0)
    {
        return;
    }
    depth=max(depth,d);
    search(tree[id].left,d+1);
    search(tree[id].right,d+1);
}

int main(void)
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&tree[i].left,&tree[i].right);
    }
    search(1,1);
    printf("%d\n",depth);
    return 0;
}
