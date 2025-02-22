#include <stdio.h>

int main(void)
{
    int n,m,i,j,t=1,x,y,r,z,temp;
    scanf("%d%d",&n,&m);
    int arr[n][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            arr[i][j]=t;
            t++;
        }
    }
    while(m)
    {
        scanf("%d%d%d%d",&x,&y,&r,&z);
        x--;
        y--;
        if(z)
        {
            while(r)
            {
                for(i=0;i<2*r;i++)
                {
                    temp=arr[x-r][y-r+1+i];
                    arr[x-r][y-r+1+i]=arr[x-r+1+i][y+r];
                    arr[x-r+1+i][y+r]=arr[x+r][y+r-1-i];
                    arr[x+r][y+r-1-i]=arr[x+r-1-i][y-r];
                    arr[x+r-1-i][y-r]=temp;
                }
                r--;
            }
        }
        else
        {
            while(r)
            {
                for(i=0;i<2*r;i++)
                {
                    temp=arr[x-r][y-r+1+i];
                    arr[x-r][y-r+1+i]=arr[x+r-1-i][y-r];
                    arr[x+r-1-i][y-r]=arr[x+r][y+r-1-i];
                    arr[x+r][y+r-1-i]=arr[x-r+1+i][y+r];
                    arr[x-r+1+i][y+r]=temp;
                }
                r--;
            }
        }
        m--;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
}
