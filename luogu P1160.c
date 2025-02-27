#include <stdio.h>
#include <stdlib.h>

#define MAX 1000001

int head=1,tail=1;
int left[MAX]={0},right[MAX]={0};

void insert(int target,int id,int dir)
{
    if(dir==0)
    {
        if(left[target]!=0)
        {
            right[left[target]]=id;
        }
        left[id]=left[target];
        right[id]=target;
        left[target]=id;
        if(head==target)
        {
            head=id;
        }
    }
    else
    {
        if(right[target]!=0)
        {
            left[right[target]]=id;
        }
        right[id]=right[target];
        left[id]=target;
        right[target]=id;
        if(tail==target)
        {
            tail=id;
        }
    }
}

void delete(int key)
{
    if(left[key])
    {
        right[left[key]]=right[key];
    }
    if(right[key])
    {
        left[right[key]]=left[key];
    }
    if(head==key)
    {
        head=right[key];
    }
    if(tail==key)
    {
        tail=left[key];
    }
    if(head==0)
    {
        tail=0;
    }
    if(tail==0)
    {
        head=0;
    }
    left[key]=0;
    right[key]=0;
}

void print(void)
{
    if(head==0)
    {
        return;
    }
    else
    {
        int temp=head;
        while(temp)
        {
            printf("%d ",temp);
            temp=right[temp];
        }
        printf("\n");
    }
}

int main(void)
{
    int n,i,dir,target;
    scanf("%d",&n);
    for(i=2;i<=n;i++)
    {
        scanf("%d%d",&target,&dir);
        insert(target,i,dir);
    }
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&target);
        delete(target);
    }
    print();
    return 0;
}
