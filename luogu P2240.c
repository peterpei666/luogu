#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    double m;
    double v;
    double a;
} gold;

int compare(const void* a,const void* b)
{
    gold* g1=(gold*)a;
    gold* g2=(gold*)b;
    if (g2->a > g1->a)
    {
        return 1;
    }
    if (g2->a < g1->a)
    {
        return -1;
    }
    return 0;
}

int main(void)
{
    int n,t,i;
    double value=0;
    scanf("%d%d",&n,&t);
    gold* list=(gold*)malloc(n*sizeof(gold));
    for(i=0;i<n;i++)
    {
        scanf("%lf%lf",&list[i].m,&list[i].v);
        list[i].a=list[i].v/list[i].m;
    }
    qsort(list,n,sizeof(gold),compare);
    for(i=0;i<n&&t>0;i++)
    {
        if(t>=list[i].m)
        {
            value+=list[i].v;
            t-=list[i].m;
        }
        else
        {
            value+=t*list[i].a;
            t=0;
        }
    }
    printf("%.2lf\n",value);
    free(list);
    return 0;
}
