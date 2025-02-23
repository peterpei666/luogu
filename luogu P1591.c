#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int main(void)
{
    int n,m,k,i,j,t,count,temp;
    scanf("%d",&m);
    int ans[20];
    for(t=0;t<m;t++)
    {
        count=0;
        scanf("%d%d",&n,&k);
        int* mult=(int*)calloc(MAX,sizeof(int));
        for(temp=0;temp<MAX;temp++)
        {
            mult[temp]=0;
        }
        mult[MAX-1]=1;
        for(i=1;i<=n;i++)
        {
            for(j=MAX-1;j>=0;j--)
            {
                mult[j]*=i;
            }
            for(j=MAX-1;j>0;j--)
            {
                mult[j-1]+=mult[j]/100000;
                mult[j]%=100000;
            }
        }
        if(k!=0)
        {
            for(j=MAX-1;j>=0;j--)
            {
                while(mult[j])
                {
                    if(k==mult[j]%10)
                    {
                        count++;
                    }
                    mult[j]/=10;
                }
            }
        }
        else
        {
            j=0;
            while(mult[j]==0)
            {
                j++;
            }
            while(mult[j])
            {
                if(mult[j]%10==0)
                {
                    count++;
                }
                mult[j]/=10;
            }
            j++;
            while(j<MAX)
            {
                temp=0;
                while(mult[j])
                {
                    if(mult[j]%10)
                    {
                        temp++;
                    }
                    mult[j]/=10;
                }
                count+=5-temp;
            }
        }
        ans[t]=count;
        free(mult);
    }
    for(t=0;t<m;t++)
    {
        printf("%d\n",ans[t]);
    }
    return 0;
}

