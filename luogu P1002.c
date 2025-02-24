#include <stdio.h>

int compare(int x,int y,int x2,int y2)
{
    if(x==x2&&y==y2)
    {
        return 1;
    }
    else if(x==x2-2)
    {
        if(y==y2-1||y==y2+1)
        {
            return 1;
        }
    }
    else if(x==x2-1)
    {
        if(y==y2-2||y==y2+2)
        {
            return 1;
        }
    }
    else if(x==x2+1)
    {
        if(y==y2-2||y==y2+2)
        {
            return 1;
        }
    }
    else if(x==x2+2)
    {
        if(y==y2-1||y==y2+1)
        {
            return 1;
        }
    }
    return 0;
}

int main(void)
{
    int x1,y1,x2,y2,i,j;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    long long arr[x1+1][y1+1];
    for(j=0;j<=y1;j++)
    {
        if(compare(x1,j,x2,y2))
        {
            arr[x1][j]=0;
        }
        else
        {
            arr[x1][j]=1;
        }
    }
    for(i=0;i<=x1;i++)
    {
        if(compare(i,y1,x2,y2))
        {
            arr[i][y1]=0;
        }
        else
        {
            arr[i][y1]=1;
        }
    }
    for(i=x1-1;i>=0;i--)
    {
        for(j=y1-1;j>=0;j--)
        {
            if(compare(i,j,x2,y2))
            {
                arr[i][j]=0;
            }
            else
            {
                arr[i][j]=arr[i+1][j]+arr[i][j+1];
            }
        }
    }
    printf("%lld\n",arr[0][0]);
    return 0;
}
