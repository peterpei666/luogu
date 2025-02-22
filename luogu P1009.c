#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int main(void)
{
    int n,i,j;
    scanf("%d",&n);
    int* mult=(int*)calloc(MAX,sizeof(int));
    int* sum=(int*)calloc(MAX,sizeof(int));
    mult[MAX-1]=1;
    for(i=1;i<=n;i++)
    {
        for(j=MAX-1;j>=0;j--)
        {
            mult[j]*=i;
        }
        for(j=MAX-1;j>0;j--)
        {
            mult[j-1]+=mult[j]/1000000;
            mult[j]%=1000000;
        }
        for(j=MAX-1;j>=0;j--)
        {
            sum[j]+=mult[j];
        }
        for(j=MAX-1;j>0;j--)
        {
            sum[j-1]+=sum[j]/1000000;
            sum[j]%=1000000;
        }
    }
    for(i=0;i<MAX;i++)
    {
        if(sum[i]>0)
        {
            break;
        }
    }
    printf("%d",sum[i]);
    i++;
    while(i<MAX)
    {
        printf("%06d",sum[i]);
        i++;
    }
    printf("\n");
    free(mult);
    free(sum);
    return 0;
}
