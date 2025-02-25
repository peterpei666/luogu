#include <stdio.h>

int list[2000002]={0};

int main(void)
{
    int min=0,m,i,n,k,f1=1,f2=1,p;
    scanf("%d",&n);
    scanf("%d",&m);
    list[m+1000000]=1;
    min+=m;
    for(i=1;i<n;i++)
    {
        f1=1;
        f2=1;
        scanf("%d",&m);
        p=m+1000000;
        for(k=0;f1||f2;k++)
        {
            if(p-k<0)
            {
                f1=0;
            }
            if(p+k>1000000)
            {
                f2=0;
            }
            if((p-k>=0&&list[p-k]==1)||(p+k<=2000000&&list[p+k]==1))
            {
                break;
            }
        }
        min+=k;
        list[p]=1;
    }
    printf("%d\n",min);
    return 0;
}
