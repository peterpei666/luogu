#include <stdio.h>
#include <stdlib.h>

#define MAX 2000

int main(void)
{
    int i,n,j,sum=0,num;
    int* mult=(int*)calloc(MAX,sizeof(int));
    int a[500]={0};
    scanf("%d",&n);
    mult[MAX-1]=1;
    for(i=0;sum<n;i++)
    {
        sum+=i+2;
        a[i]=i+2;
    }
    num=i-1;
    if(sum-n==1)
    {
        a[0]=0;
        a[num]++;
    }
    else
    {
        a[sum-n-2]=0;
    }
    for(i=0;i<=num;i++)
    {
        if(a[i])
        {
            for(j=MAX-1;j>=0;j--)
            {
                mult[j]*=a[i];
            }
            for(j=MAX-1;j>0;j--)
            {
                mult[j-1]+=mult[j]/100000;
                mult[j]%=100000;
            }
        }
    }
    for(i=0;i<=num;i++)
    {
        if(a[i])
        {
            printf("%d ",a[i]);
        }
    }
    printf("\n");
    j=0;
    while(mult[j]==0)
    {
        j++;
    }
    printf("%d",mult[j]);
    while(j<MAX-1)
    {
        j++;
        printf("%05d",mult[j]);
    }
    printf("\n");
    return 0;
}
