#include <stdio.h>


int main(void)
{
    int n,m,l,r,count,i,j,k;
    scanf("%d%d",&n,&m);
    int list[n];
    for(i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
    }
    while(m)
    {
        count=0;
        scanf("%d%d",&l,&r);
        for(i=l-1;i<r-2;i++)
        {
            if(list[i]%4)
            {
                continue;
            }
            for(j=i+1;j<r-1;j++)
            {
                if(list[j]%2)
                {
                    continue;
                }
                if(list[i]==2*list[j])
                {
                    for(k=j+1;k<r;k++)
                    {
                        if(list[k]%3)
                        {
                            continue;
                        }
                        if(3*list[j]==2*list[k])
                        {
                            count++;
                        }
                    }
                }
                else
                {
                    continue;
                }
            }
        }
        printf("%d\n",count);
        m--;
    }
    return 0;
}
