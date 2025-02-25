#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n,i;
    long long ans;
    scanf("%d",&n);
    int* list=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        scanf("%d",&list[i]);
    }
    ans=list[0];
    for(i=1;i<n;i++)
    {
        if(list[i]>list[i-1])
        {
            ans+=list[i]-list[i-1];
        }
    }
    printf("%lld\n",ans);
    free(list);
    return 0;
}
