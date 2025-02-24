#include <stdio.h>

#define MAX 1000

int main(void)
{
    int n,i,j;
    int arr1[MAX]={0},arr2[MAX]={0},temp[MAX]={0};
    scanf("%d",&n);
    arr1[MAX-1]=1;
    arr2[MAX-1]=2;
    for(i=3;i<=n;i++)
    {
        if(i%2)
        {
            for(j=MAX-1;j>=0;j--)
            {
                temp[j]=arr1[j]+arr2[j];
            }
            for(j=MAX-1;j>0;j--)
            {
                temp[j-1]+=temp[j]/1000000;
                temp[j]%=1000000;
            }
            for(j=MAX-1;j>=0;j--)
            {
                arr1[j]=temp[j];
            }
        }
        else
        {
            for(j=MAX-1;j>=0;j--)
            {
                temp[j]=arr1[j]+arr2[j];
            }
            for(j=MAX-1;j>0;j--)
            {
                temp[j-1]+=temp[j]/1000000;
                temp[j]%=1000000;
            }
            for(j=MAX-1;j>=0;j--)
            {
                arr2[j]=temp[j];
            }
        }
    }
    j=0;
    while(temp[j]==0)
    {
        j++;
    }
    printf("%d",temp[j]);
    j++;
    while(j<MAX)
    {
        printf("%06d",temp[j]);
        j++;
    }
    printf("\n");
    return 0;
}
