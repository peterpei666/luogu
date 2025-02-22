#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n,i,temp;
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n+1;i++)
    {
        scanf("%d",&arr[i]);
    }
    if(n==0)
    {
        printf("%d\n",arr[0]);
        return 0;
    }
    for(i=0;i<n+1;i++)
    {
        if(arr[i]==0)
        {
            continue;
        }
        if(i!=0&&arr[i]>0)
        {
            printf("+");
        }
        else if(arr[i]<0)
        {
            printf("-");
        }
        temp=abs(arr[i]);
        if(n-i>1)
        {
            if(temp==1)
            {
                printf("x^%d",n-i);
            }
            else
            {
                printf("%dx^%d",temp,n-i);
            }
        }
        else if(n-i==1)
        {
            if(temp==1)
            {
                printf("x");
            }
            else
            {
                printf("%dx",temp);
            }
        }
        else
        {
            printf("%d",temp);
        }
    }
    printf("\n");
    return 0;
}
