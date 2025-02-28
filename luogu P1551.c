#include <stdio.h>

int father[6000];
int rank[6000];

int origin(int x)
{
    if(father[x]!=x)
    {
        father[x]=origin(father[x]);
    }
    return father[x];
}

void merge(int a,int b)
{
    int root1=origin(a);
    int root2=origin(b);
    if(root1!=root2)
    {
        if(rank[root1]<rank[root2])
        {
            father[root1]=root2;
        }
        else if(rank[root1]>rank[root2])
        {
            father[root2]=root1;
        }
        else
        {
            father[root2]=root1;
            rank[root1]++;
        }
    }
}

int main(void)
{
    int a,b,i,n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    for(i=1;i<=n;i++)
    {
        father[i]=i;
        rank[i]=1;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        merge(a,b);
    }
    for(i=1;i<=q;i++)
    {
        scanf("%d%d",&a,&b);
        if(origin(a)==origin(b))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
