#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int time;
    int country;
} person;

int main(void)
{
    int country[300000]={0};
    int n,i,m,j=0,ans=0,t,k=0,c;
    person* list=(person*)malloc(300000*sizeof(person));
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&t,&m);
        while(m)
        {
            scanf("%d",&c);
            list[j].time=t;
            list[j].country=c;
            j++;
            country[c]++;
            if(country[c]==1)
            {
                ans++;
            }
            m--;
        }
        while(k<j&&list[k].time+86400<=t)
        {
            country[list[k].country]--;
            if(country[list[k].country]==0)
            {
                ans--;
            }
            k++;
        }
        printf("%d\n",ans);
    }
    free(list);
    return 0;
}
