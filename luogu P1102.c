#include <stdio.h>
#include <stdlib.h>

#define M 2000003

typedef struct
{
    int data;
    int count;
} node;

int hash_func(int data)
{
    return data%M;
}

node hash_table[M];

int find(int data)
{
    int p=hash_func(data%M+M);
    while(hash_table[p].data&&hash_table[p].data!=data)
    {
        p=hash_func(p+1);
    }
    return p;
}

void push(int data)
{
    int p=find(data);
    hash_table[p].count++;
    hash_table[p].data=data;
}

int check(int data)
{
    if(hash_table[find(data)].data==data)
    {
        return hash_table[find(data)].count;
    }
    else
    {
        return 0;
    }
}

int main(void)
{
    int n,m,i,ans=0;
    int a[M];
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        push(a[i]);
    }
    for(i=0;i<n;i++)
    {
        ans+=check(a[i]-m);
    }
    printf("%d\n",ans);
    return 0;
}
